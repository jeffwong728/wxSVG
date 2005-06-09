//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFEFloodElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FE_FLOOD_ELEMENT_H
#define WX_SVG_FE_FLOOD_ELEMENT_H

#include "SVGElement.h"
#include "SVGFilterPrimitiveStandardAttributes.h"
#include "SVGAnimatedString.h"
#include "String.h"

class wxSVGFEFloodElement:
  public wxSVGElement,
  public wxSVGFilterPrimitiveStandardAttributes
{
  protected:
    wxSVGAnimatedString m_in1;

  public:
    inline const wxString& GetIn1() { return m_in1.GetBaseVal(); }
    inline void SetIn1(const wxString& n) { m_in1.GetBaseVal() = n; }

  public:
    inline const wxString& GetAnimatedIn1() { return m_in1.GetAnimVal(); }
    inline void SetAnimatedIn1(const wxString& n) { m_in1.GetAnimVal() = n; }

  public:
    wxSVGFEFloodElement(wxSVGDocument* doc, wxString tagName = wxT("feFlood")):
      wxSVGElement(doc, tagName) {}
    virtual ~wxSVGFEFloodElement() {}
    bool SetAttribute(const wxString& name, const wxString& value);
    virtual const wxSVGDTD GetDtd() const { return wxSVG_FEFLOOD_ELEMENT; }
};

#endif // WX_SVG_FE_FLOOD_ELEMENT_H
