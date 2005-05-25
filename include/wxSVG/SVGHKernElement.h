//////////////////////////////////////////////////////////////////////////////
// Name:        SVGHKernElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_H_KERN_ELEMENT_H
#define WX_SVG_H_KERN_ELEMENT_H

#include "SVGElement.h"
#include "String.h"

class wxSVGHKernElement:
  public wxSVGElement
{
  public:
	wxSVGHKernElement(wxSVGDocument* doc, wxString tagName = wxT("hkern")):
	  wxSVGElement(doc, tagName) {}
	virtual ~wxSVGHKernElement() {}
	bool SetAttribute(const wxString& name, const wxString& value);
	virtual const wxSVGDTD GetDtd() const { return wxSVG_HKERN_ELEMENT; }
};

#endif // WX_SVG_H_KERN_ELEMENT_H