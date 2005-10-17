//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFEColorMatrixElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FE_COLOR_MATRIX_ELEMENT_H
#define WX_SVG_FE_COLOR_MATRIX_ELEMENT_H

#include "SVGElement.h"
#include "SVGFilterPrimitiveStandardAttributes.h"
#include "SVGAnimatedString.h"
#include "SVGAnimatedEnumeration.h"
#include "SVGAnimatedNumberList.h"
#include "String.h"


enum wxSVG_FECOLORMATRIX_TYPE
{
  wxSVG_FECOLORMATRIX_TYPE_UNKNOWN = 0,
  wxSVG_FECOLORMATRIX_TYPE_MATRIX = 1,
  wxSVG_FECOLORMATRIX_TYPE_SATURATE = 2,
  wxSVG_FECOLORMATRIX_TYPE_HUEROTATE = 3,
  wxSVG_FECOLORMATRIX_TYPE_LUMINANCETOALPHA = 4
};

class wxSVGFEColorMatrixElement:
  public wxSVGElement,
  public wxSVGFilterPrimitiveStandardAttributes
{
  protected:
    wxSVGAnimatedString m_in1;
    wxSVGAnimatedEnumeration m_type;
    wxSVGAnimatedNumberList m_values;

  public:
    inline const wxSVGAnimatedString& GetIn1() const { return m_in1; }
    inline void SetIn1(const wxSVGAnimatedString& n) { m_in1 = n; }
    inline void SetIn1(const wxString& n) { m_in1.SetBaseVal(n); }

    inline const wxSVGAnimatedEnumeration& GetType() const { return m_type; }
    inline void SetType(const wxSVGAnimatedEnumeration& n) { m_type = n; }
    inline void SetType(char n) { m_type.SetBaseVal(n); }

    inline const wxSVGAnimatedNumberList& GetValues() const { return m_values; }
    inline void SetValues(const wxSVGAnimatedNumberList& n) { m_values = n; }
    inline void SetValues(const wxSVGNumberList& n) { m_values.SetBaseVal(n); }

  public:
    wxSVGFEColorMatrixElement(wxString tagName = wxT("feColorMatrix")):
      wxSVGElement(tagName) {}
    virtual ~wxSVGFEColorMatrixElement() {}
    wxXmlNode* CloneNode(bool deep = true) { return new wxSVGFEColorMatrixElement(*this); }
    bool HasAttribute(const wxString& name);
    wxString GetAttribute(const wxString& name);
    bool SetAttribute(const wxString& name, const wxString& value);
    virtual const wxSVGDTD GetDtd() const { return wxSVG_FECOLORMATRIX_ELEMENT; }
};

#endif // WX_SVG_FE_COLOR_MATRIX_ELEMENT_H
