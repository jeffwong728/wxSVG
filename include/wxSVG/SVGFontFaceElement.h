//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFontFaceElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FONT_FACE_ELEMENT_H
#define WX_SVG_FONT_FACE_ELEMENT_H

#include "SVGElement.h"
#include "String.h"

class wxSVGFontFaceElement:
  public wxSVGElement
{
  public:
    wxSVGFontFaceElement(wxString tagName = wxT("font-face")):
      wxSVGElement(tagName) {}
    virtual ~wxSVGFontFaceElement() {}
    wxXmlNode* CloneNode(bool deep = true) { return new wxSVGFontFaceElement(*this); }
    bool HasAttribute(const wxString& name);
    wxString GetAttribute(const wxString& name);
    bool SetAttribute(const wxString& name, const wxString& value);
    virtual const wxSVGDTD GetDtd() const { return wxSVG_FONT_FACE_ELEMENT; }
};

#endif // WX_SVG_FONT_FACE_ELEMENT_H
