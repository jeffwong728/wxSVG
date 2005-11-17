//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFEComponentTransferElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FE_COMPONENT_TRANSFER_ELEMENT_H
#define WX_SVG_FE_COMPONENT_TRANSFER_ELEMENT_H

#include "SVGElement.h"
#include "SVGFilterPrimitiveStandardAttributes.h"
#include "SVGAnimatedString.h"
#include "String.h"
#include "Element.h"

class wxSVGFEComponentTransferElement:
  public wxSVGElement,
  public wxSVGFilterPrimitiveStandardAttributes
{
  protected:
    wxSVGAnimatedString m_in1;

  public:
    inline const wxSVGAnimatedString& GetIn1() const { return m_in1; }
    inline void SetIn1(const wxSVGAnimatedString& n) { m_in1 = n; }
    inline void SetIn1(const wxString& n) { m_in1.SetBaseVal(n); }

  public:
    wxSVGFEComponentTransferElement(wxString tagName = wxT("feComponentTransfer")):
      wxSVGElement(tagName) {}
    virtual ~wxSVGFEComponentTransferElement() {}
    wxXmlNode* CloneNode(bool deep = true) { return new wxSVGFEComponentTransferElement(*this); }
    bool HasAttribute(const wxString& name);
    wxString GetAttribute(const wxString& name);
    bool SetAttribute(const wxString& name, const wxString& value);
    wxXmlAttrHash GetAttributes() const;
    virtual wxSVGDTD GetDtd() const { return wxSVG_FECOMPONENTTRANSFER_ELEMENT; }
};

#endif // WX_SVG_FE_COMPONENT_TRANSFER_ELEMENT_H
