//////////////////////////////////////////////////////////////////////////////
// Name:        SVGTRefElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_T_REF_ELEMENT_H
#define WX_SVG_T_REF_ELEMENT_H

#include "SVGTextPositioningElement.h"
#include "SVGURIReference.h"
#include "String.h"

class wxSVGTRefElement:
  public wxSVGTextPositioningElement,
  public wxSVGURIReference
{
  public:
	wxSVGTRefElement(wxSVGDocument* doc, wxString tagName = wxT("tref")):
	  wxSVGTextPositioningElement(doc, tagName) {}
	virtual ~wxSVGTRefElement() {}
	bool SetAttribute(const wxString& name, const wxString& value);
	virtual const wxSVGDTD GetDtd() const { return wxSVG_TREF_ELEMENT; }
};

#endif // WX_SVG_T_REF_ELEMENT_H