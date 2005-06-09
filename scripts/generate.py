##############################################################################
## Name:        generate.py
## Purpose:     generates the most headers from idl, but with some changes
## Author:      Alex Thuering
## Created:     2005/01/19
## RCS-ID:      $Id: generate.py,v 1.5 2005-06-09 00:17:38 ntalex Exp $
## Copyright:   (c) 2005 Alex Thuering
## Notes:       some modules adapted from svgl project
##############################################################################

##############################################################################
## generates the most headers from idl, but with some changes:
##   - all properties in idl are "readonly", but I generate not only
##     get methods, but also set methods.
##     This allow you to call:
##       rect->SetWidth(100)
##     instead of
##       rect->SetAttrubite("width", "100");
##  - for animated properties (f.e.: SVGAnimatedLength width)
##    2 methods are generated: GetWidth() and GetAnimatedWidth()
##    So to get (or set) width you need to call
##       rect->GetWidth()
##    instead of 
##       rect->GetWidth().GetBaseVal()
##############################################################################

import parse_idl
import cpp
import cppHeader
import enum_map
import string
import mapDtdIdl
import interfaces
import config
import genAnimated
import genList
import genCSS
import genFile
import os

used_lists = []
used_animated = []

def find_dtd_attr_in_inherit(classdecl):
    if len(classdecl.attributes):
        for attr in classdecl.attributes:
            if mapDtdIdl.attributes_idl_dtd.has_key(attr):
                return 1

    for inh in classdecl.inherits:
        try:
            res = find_dtd_attr_in_inherit(parse_idl.class_decls[inh])
            if res > 0:
                return 1
        except KeyError:
            pass
    return 0


if len(parse_idl.class_decls):
    for (classname, classdecl) in parse_idl.class_decls.items():

        if string.find(classname, "Animated") >=0 and classname not in ["SVGAnimatedPathData","SVGAnimatedPoints",""]:
            used_animated.append(classname)
            continue
        if string.find(classname, "List") >=0:
            used_lists.append(classname)
            continue

        # print classdecl
        header = cppHeader.Header(classname, "generate.py")

        includes=[]
        fwd_decls=[]
        doGetAttrByName=0

        output = ''
        cpp_output = ''
		
		# enums
        for enum in classdecl.enums:
            output = output + '\nenum %s\n{\n'%(cpp.fix_typename(enum.name))
            if len(enum.const_decls):
                output = output + '  %s'%(cpp.fix_typename('%s'%enum.const_decls[0]))
                if len(enum.const_decls[1:]):
                    for const_decl in enum.const_decls[1:]:
                        output = output + ',\n  %s'%(cpp.fix_typename('%s'%const_decl))
            output = output + '\n};\n\n'

        # inheritance
        output = output + "class %s"%(cpp.fix_typename(classname))
        if len(classdecl.inherits):
            first = 1
            for inherit in classdecl.inherits:
                pos = string.find(inherit, "::")
                if pos>0:
                    inherit = inherit[pos+2:]
                if first:
                    output = output + ':\n'
                    first = 0
                else:
                    output = output + ',\n'
                output = output + '  public %s'%(cpp.fix_typename(inherit))
                includes.append(inherit)
        output = output + '\n{\n'
        
        public = ''
        protected = ''

        ######## attributes ##########        
        attributes=[]

        exclude_attributes=[] # really method that set/get
        try:
            exclude_attributes=interfaces.interfaces[classname].exclude_attributes
        except KeyError:
            pass


        for attr in classdecl.attributes:
            if (attr.name in exclude_attributes):
                continue
            typename = attr.type.name
            pos = string.find(attr.type.name, 'Animated')
            
            # is Attribute an Element ?
            ispointer = False
            isenum = False
            pos = string.find(attr.type.name, 'Element')
            if pos > 0:
                fwd_decls.append(typename)
                typename = typename+'*'
                ispointer=1
            else:
                if attr.type.name=="unsigned short":# or string.find(attr.type.name, 'Enumeration')>=0:
                    try:
                        enumname = enum_map.enum_map[classname+'::'+attr.name]
                        isenum = True
                        if attr.type.name=="unsigned short":
                            typename = enumname
                        else:
                            pos = string.find(attr.type.name, 'Animated')
                            if pos >= 0:
                                typename = 'SVGAnimated%s'%enumname
                                isenum = False
                            else:
                                typename = string.replace(typename, 'Enumeration', enumname)
                            # typename = classdecl.enums[numtype].name
                    except KeyError: # gen enum_map
                        try:
                            tmp = classdecl.enums[0].name
                        except IndexError:
                            # maybe a UnitType
                            for inh in ["SVGUnitTypes", "SVGRenderingIntent"]:                            
                                if inh in classdecl.inherits:
                                    tmp = parse_idl.class_decls[inh].enums[0].name
                                    break
                                else:
                                    tmp = "0"
                        print "enum_map.py is not up-to-date. Please remove it, copy and paste what's dumped by this script in enum_map.py then rerun again"
                        print '"'+classname+'::'+attr.name +'": "' + tmp + '" ,'

                elif typename=="DOMString":
                    if "String" not in includes:
                        includes.append("String")
                else:
                    if cpp.fix_typename(typename) not in cpp.builtin_types:
                        if typename not in includes:
                            includes.append(typename)
            typename = cpp.fix_typename(typename)


            attributes.append((typename, attr.name, ispointer, isenum))
            # get by name
            try:
                entity_name = mapDtdIdl.attributes_idl_dtd[attr]
                doGetAttrByName=1
            except KeyError:
                pass
        
        # exclude_methods
        exclude_methods=[]
        try:
            exclude_methods=interfaces.interfaces[classname].exclude_methods
        except KeyError:
            pass
        
        # include_get_set_attributes
        include_get_set_attributes=[]
        try:
            for attr in interfaces.interfaces[classname].include_get_set_attributes:
                attributes.append(attr)
        except KeyError:
            pass

        ############### get/set methods #################
        if len(attributes)>0:
            
            # fields
            for (typestr, attrname, ispointer, isenum) in attributes:
                if attrname not in ['valueAsString', 'valueInSpecifiedUnits']:
                    attrname = cpp.make_attr_name(attrname)
                    protected = protected +'    '+typestr+' ' + attrname + ';\n'
            
            # get/set methods
            animatedStr = ''
            for (typestr, attrname, ispointer, isenum) in attributes:
                
                animated = 0
                typestrBase = ""
                pos = string.find(typestr, 'Animated')
                if pos>=0: # SVGAnimatedTypename
                    typestrBase = typestr[pos+len('Animated'):]
                    typestr = genAnimated.getBaseType(typestrBase)
                    animated = 1
                
                # get
                methodName = 'Get' + string.upper(attrname[0])+attrname[1:]
                if(methodName in exclude_methods):
                    continue
                exclude_methods.append(methodName)
                
                const=''
                ret_str = typestr
                if typestr == "wxString" and attrname not in ['valueAsString', 'valueInSpecifiedUnits']:
                    ret_str = 'const ' + ret_str + '&'
                elif (typestr[0:5] == "wxSVG" or typestr[0:5] == "wxCSS") and typestr[0:6] != "wxSVG_" and not ispointer:
                    ret_str = ret_str + '&'
                elif not ispointer:
                    const=' const'
                ret_str = ret_str + ' '

                attrname_cpp = cpp.make_attr_name(attrname)
                
                inline = ''
                body_str = ';'
                if attrname not in ['valueAsString', 'valueInSpecifiedUnits']:
                  inline = 'inline '
                  if animated:
                      body_str = ' { return %s.GetBaseVal(); }'%attrname_cpp
                      methodName2 = 'GetAnimated' + string.upper(attrname[0])+attrname[1:]
                      body_str2 = ' { return %s.GetAnimVal(); }'%attrname_cpp
                      animatedStr = animatedStr + '    ' + inline + ret_str + methodName2 + '()' + const + body_str2 + '\n'
                  else:
                      body_str = ' { return %s; }'%attrname_cpp
                
                public = public + '    ' + inline + ret_str + methodName + '()' + const + body_str + '\n'
                    

                # set
                methodName = 'Set' + string.upper(attrname[0])+attrname[1:]
                if(methodName in exclude_methods):
                    continue
                exclude_methods.append(methodName)
                
                params_str = '(%s n)'%(typestr)
                if typestr in cpp.builtin_types:
                    params_str = '(const %s n)'%(typestr)
                elif ispointer==0:
                    params_str = '(const %s& n)'%(typestr)
                
                inline = ''
                body_str = ';'
                if attrname not in ['valueAsString', 'valueInSpecifiedUnits']:
                    inline = 'inline '
                    if animated:
                        set_str = ".SetValue(n)"
                        if typestrBase in ["String", "Length", "Number", "Rect", "Angle", "PreserveAspectRatio"] or typestr in cpp.builtin_types or string.find(typestrBase, "List")>0:
                            set_str = " = n"
                        body_str = ' { %s.GetBaseVal()%s; '%(attrname_cpp,set_str) + '}'
                        methodName2 = 'SetAnimated' + string.upper(attrname[0])+attrname[1:]
                        body_str2 = ' { %s.GetAnimVal()%s; '%(attrname_cpp,set_str) + '}'
                        animatedStr = animatedStr + '    ' + inline + 'void ' + methodName2 + params_str + body_str2 + '\n'
                    else:
                        body_str = ' { %s = n; '%attrname_cpp + '}'
                public = public + '    ' + inline + 'void ' + methodName + params_str + body_str + '\n'
                public = public + '\n'
                if animated:
                    animatedStr = animatedStr + '\n'
            if animated:
                public = public + '  public:\n'
                public = public + animatedStr

    
        try:
            for i in interfaces.interfaces[classname].include_attributes:
                public = public+i
            
        except KeyError:
            pass
        
        ################# wxSVGStylable ####################
        if classname == "SVGStylable":
            public = public + "  public:\n"
            for attr in genCSS.attibutes:
                valueType = attr.valueType
                if valueType not in cpp.builtin_types:
                    valueType = "const " + valueType + "&"
                public = public + '    inline void Set%s(%s value) { m_style.Set%s(value); }\n'%(attr.name, valueType, attr.name)
                valueType = attr.valueType
                if len(attr.function) == 0:
                    valueType = "const " + valueType + "&"
                public = public + '    inline %s Get%s() { return m_style.Get%s(); }\n'%(valueType, attr.name, attr.name)
                public = public + '    inline bool Has%s() { return m_style.Has%s(); }\n'%(attr.name, attr.name)
                public = public + '    \n'
        

        ################# constructor #######################
        methods_str = ''
        
        has_constructor = 0
        try:
            has_constructor=interfaces.interfaces[classname].user_defined_constructor
        except KeyError:
            pass
        if has_constructor==0:
            init_attibutes = ""
            try:
                for (typestr, attrname, ispointer, isenum) in attributes:
                    attrname=cpp.make_attr_name(attrname)
                    if typestr in cpp.number_types:
                        init_attibutes = init_attibutes + ", %s(0)"%attrname
                    elif ispointer:
                        init_attibutes = init_attibutes + ", %s(NULL)"%attrname
                    elif isenum:
                        init_attibutes = init_attibutes + ", %s(%s(0))"%(attrname,typestr)
                for (attrname,ispointer) in interfaces.interfaces[classname].include_attributes_init:
                    attrname=cpp.make_attr_name(attrname)
                    if ispointer:
                        init_attibutes = init_attibutes + ", %s(NULL)"%attrname
                    else:
                        init_attibutes = init_attibutes + ", %s(0)"%attrname
            except KeyError:
                pass
            cname = cpp.fix_typename(classname)
            if string.find(classname, "Element")>0:
                # first find the directly inherited "Element" class
                # generally SVGElement, but it can be  SVGGradientElement for ex.
                element_inherit=None
                for inh in classdecl.inherits:
                    if string.find(inh, "Element")>0:
                        element_inherit=cpp.fix_typename(inh)
                        break
                element_string=''
                if mapDtdIdl.elements_idl_dtd.has_key(classdecl):
                    element_string=mapDtdIdl.elements_idl_dtd[classdecl]
                methods_str = methods_str + '    %s(wxSVGDocument* doc, wxString tagName = wxT("%s")):\n      %s(doc, tagName)%s {}\n'%(cname, element_string, element_inherit, init_attibutes)
            elif classname[0:10] == "SVGPathSeg" and len(classname)>10:
                seg_type = string.upper(classname[10:])
                strs = ["ABS", "REL", "HORIZONTAL", "VERTICAL", "CUBIC", "QUADRATIC", "SMOOTH"]
                for s in strs:
                    pos = string.find(seg_type, s)
                    if pos>0:
                        seg_type = seg_type[:pos] + "_" + seg_type[pos:]  
                seg_type = "wxPATHSEG_" + seg_type
                methods_str = methods_str + '    %s():\n      wxSVGPathSeg(%s)%s {}\n'%(cname, seg_type, init_attibutes)
            elif len(init_attibutes)>0:
                methods_str = methods_str + '    %s(): %s {}\n'%(cname, init_attibutes[2:])
        
        ################# destructor #######################
        has_destructor = 0
        try:
            has_destructor=interfaces.interfaces[classname].user_defined_destructor
        except KeyError:
            pass
        if has_destructor==0:
            methods_str = methods_str + '    virtual ~%s() {}\n'%(cpp.fix_typename(classname))
        
        ################### methods #########################
        try:
            for i in interfaces.interfaces[classname].include_methods:
                methods_str = methods_str+i
        except KeyError:
            pass
        
        for meth in classdecl.methods:
            method_ret = ''
            return_type = cpp.fix_typename(meth.return_type.name)
            if return_type not in cpp.builtin_types:
                if meth.return_type.name in ["DOMString"]: # confusion between typedef and class
                    if "String" not in includes:
                        includes.append("String")
                else:
                    if meth.return_type.name not in includes:
                        includes.append(meth.return_type.name)
            if meth.return_type.name in ["SVGDocument", "Element"]:
                method_ret = return_type + '* '
            elif meth.return_type.name in ["css::CSSValue"]:
                method_ret = 'const ' + return_type + '& '
            else:
                method_ret = return_type + ' '
            
            method_name = string.upper(meth.name[0]) + meth.name[1:];
            if method_name in exclude_methods:
                continue
            method_decl = method_name + '('
            count=0
            for arg in meth.args:
                if count>0:
                    method_decl = method_decl +', '
                arg_type = cpp.fix_typename(arg.type.name)
                if arg_type not in cpp.builtin_types:
                    if arg.inout == 'in':
                        method_decl = method_decl + 'const %s& %s'%(arg_type, arg.name)
                    elif arg.inout == 'inout':
                        method_decl = method_decl + '%s* %s'%(arg_type, arg.name)
                    elif arg.inout == 'out':
                        method_decl = method_decl + '%s* %s'%(arg_type, arg.name)

                    if arg.type.name in ["DOMString"]: # confusion between typedef and class
                        if "String" not in includes:
                            includes.append("String")
                    else:
                        if arg.type.name not in includes:
                            includes.append(arg.type.name)
                else:
                    if arg_type == "unsigned short":
                        arg_type = cpp.fix_typename(enum_map.enum_map[classname+'::'+arg.name])
                    method_decl = method_decl + '%s %s'%(arg_type, arg.name)
                count = count+1
            
            method_decl = method_decl + ')'
            methods_str = methods_str + '    virtual ' + method_ret + method_decl + ';\n';
            method_decl = cpp.fix_typename(classname) + "::" + method_decl;
            cpp_output = cpp_output + method_ret + method_decl + '\n{\n';
            if return_type != "void":
                if string.find(method_ret, "*") < 0:
                    cpp_output = cpp_output + '  ' + method_ret + 'res'
                    if return_type in cpp.builtin_types:
                        cpp_output = cpp_output + ' = 0';
                    cpp_output = cpp_output + ';\n'
                else:
                    cpp_output = cpp_output + '  ' + method_ret + 'res = new ' + return_type + '();\n'
                cpp_output = cpp_output + '  ' + 'return res;'
            cpp_output = cpp_output + '\n}\n\n'
        
        has_dtd_attributes=find_dtd_attr_in_inherit(classdecl)
        if has_dtd_attributes==1 and "SetAttribute" not in exclude_methods:
            methods_str = methods_str + '    bool SetAttribute(const wxString& name, const wxString& value);\n';
            if "String" not in includes:
                includes.append("String")
            doGetAttrByName=1
            if classname in ["SVGStylable"]: #makeSetAttribute.customParser
                protected = protected + '    bool SetCustomAttribute(const wxString& name, const wxString& value);\n';

        element_string=None
        if mapDtdIdl.elements_idl_dtd.has_key(classdecl):
            element_string=mapDtdIdl.elements_idl_dtd[classdecl]
            typename = cpp.fix_typename("SVGDTD")
            dtdname = "SVG_" + string.upper(element_string) + "_ELEMENT"
            dtdname = cpp.fix_typename(cpp.make_name(dtdname))
            methods_str = methods_str + '    virtual const %s GetDtd() const { return %s; }\n'%(typename,dtdname)
        
        try:
            fwds = interfaces.interfaces[classname].include_fwd_decls
            for toto in fwds:
                if toto not in fwd_decls:
                    fwd_decls.append(toto)
        except KeyError:
            pass
        
        if len(methods_str):
            if len(public):
                public = public + '  public:\n'
            public = public + methods_str
        
        # end struct
        public = public + '};'
        
        ###################### includes #############################
        includestr=""
        for inc in includes:
            if inc==classname:
                continue
            realname = inc
            pos = string.find(inc, "::")
            if pos>0:
                realname = inc[pos+2:]
            includestr = includestr + "#include \"%s.h\"\n"%(realname)

        try:
            incs = interfaces.interfaces[classname].include_includes
            for i in incs:
                if i[0] == '<':
                    includestr = includestr + '#include %s\n'%(i)
                else:
                    includestr = includestr + '#include "%s.h"\n'%(i)
        except KeyError:
            pass
        if len(includestr):
            includestr = includestr + '\n'
        
        fwd_decls_namespace = { "svg":[] }
        for i in fwd_decls:
            pos = string.find(i, "::")
            nspace = i[:pos]
            if pos>=0:
                if fwd_decls_namespace.has_key(nspace):
                    fwd_decls_namespace[nspace].append(i[pos+2:])
                else:
                    fwd_decls_namespace[nspace]=[i[pos+2:]]
            else:
                if i!='Element':
                    fwd_decls_namespace['svg'].append(i)

        if len(fwd_decls_namespace) > 0:
            fwd_decl_str = ''
            for (nspace, classnames) in fwd_decls_namespace.items():
                for i in classnames:
                    fwd_decl_str = fwd_decl_str + 'class %s;\n'%cpp.fix_typename(i)
        if len(fwd_decl_str):
          fwd_decl_str = fwd_decl_str + '\n'
        
        ##################### write header files #############################
        if len(protected):
            output = output + '  protected:\n' + protected + '\n'
        output = output + '  public:\n' + public
        header.add_content(fwd_decl_str + includestr + output)
        header.dump(path=config.include_dir)
        
        ############## write cpp files (disabled) ############################
        if cpp_output != '' and string.find(classname, "List") < 0:
            cpp_output = '''
/////////////////////////////////////////////////////////////////////////////
// Name:        %s.cpp
// Purpose:     
// Author:      Alex Thuering
// Created:     2005/04/29
// RCS-ID:      $Id: generate.py,v 1.5 2005-06-09 00:17:38 ntalex Exp $
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "%s.h"\n
'''%(classname,classname) + cpp_output
            #f = genFile.gfopen(os.path.join(config.src_dir, "%s.cpp"%classname),'w')
            #f.write(cpp_output)

###################### Generate animated, lists, setattribute, ... ##########
for i in used_animated:
    genAnimated.generate(string.replace(i,'SVGAnimated',''))

for i in used_lists:
    name = string.replace(string.replace(i,'List',''),'SVG','')
    genList.generate(name)

genCSS.generate()

import genSetAttribute
import genSvgElement

