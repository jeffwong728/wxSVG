//////////////////////////////////////////////////////////////////////////////
// Name:        SVGTSpanElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_T_SPAN_ELEMENT_H
#define WX_SVG_T_SPAN_ELEMENT_H

#include "SVGTextPositioningElement.h"
#include "String.h"

class wxSVGTSpanElement:
  public wxSVGTextPositioningElement
{
  public:
    wxSVGTSpanElement(wxSVGDocument* doc, wxString tagName = wxT("tspan")):
      wxSVGTextPositioningElement(doc, tagName) {}
    virtual ~wxSVGTSpanElement() {}
    bool SetAttribute(const wxString& name, const wxString& value);
    virtual const wxSVGDTD GetDtd() const { return wxSVG_TSPAN_ELEMENT; }
};

#endif // WX_SVG_T_SPAN_ELEMENT_H
