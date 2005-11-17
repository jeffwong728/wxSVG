//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFEOffsetElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FE_OFFSET_ELEMENT_H
#define WX_SVG_FE_OFFSET_ELEMENT_H

#include "SVGElement.h"
#include "SVGFilterPrimitiveStandardAttributes.h"
#include "SVGAnimatedString.h"
#include "SVGAnimatedNumber.h"
#include "String.h"
#include "Element.h"

class wxSVGFEOffsetElement:
  public wxSVGElement,
  public wxSVGFilterPrimitiveStandardAttributes
{
  protected:
    wxSVGAnimatedString m_in1;
    wxSVGAnimatedNumber m_dx;
    wxSVGAnimatedNumber m_dy;

  public:
    inline const wxSVGAnimatedString& GetIn1() const { return m_in1; }
    inline void SetIn1(const wxSVGAnimatedString& n) { m_in1 = n; }
    inline void SetIn1(const wxString& n) { m_in1.SetBaseVal(n); }

    inline const wxSVGAnimatedNumber& GetDx() const { return m_dx; }
    inline void SetDx(const wxSVGAnimatedNumber& n) { m_dx = n; }
    inline void SetDx(float n) { m_dx.SetBaseVal(n); }

    inline const wxSVGAnimatedNumber& GetDy() const { return m_dy; }
    inline void SetDy(const wxSVGAnimatedNumber& n) { m_dy = n; }
    inline void SetDy(float n) { m_dy.SetBaseVal(n); }

  public:
    wxSVGFEOffsetElement(wxString tagName = wxT("feOffset")):
      wxSVGElement(tagName) {}
    virtual ~wxSVGFEOffsetElement() {}
    wxXmlNode* CloneNode(bool deep = true) { return new wxSVGFEOffsetElement(*this); }
    bool HasAttribute(const wxString& name);
    wxString GetAttribute(const wxString& name);
    bool SetAttribute(const wxString& name, const wxString& value);
    wxXmlAttrHash GetAttributes() const;
    virtual wxSVGDTD GetDtd() const { return wxSVG_FEOFFSET_ELEMENT; }
};

#endif // WX_SVG_FE_OFFSET_ELEMENT_H
