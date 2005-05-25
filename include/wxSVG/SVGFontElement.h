//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFontElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FONT_ELEMENT_H
#define WX_SVG_FONT_ELEMENT_H

#include "SVGElement.h"
#include "SVGExternalResourcesRequired.h"
#include "SVGStylable.h"
#include "String.h"

class wxSVGFontElement:
  public wxSVGElement,
  public wxSVGExternalResourcesRequired,
  public wxSVGStylable
{
  public:
	wxSVGFontElement(wxSVGDocument* doc, wxString tagName = wxT("font")):
	  wxSVGElement(doc, tagName) {}
	virtual ~wxSVGFontElement() {}
	bool SetAttribute(const wxString& name, const wxString& value);
	virtual const wxSVGDTD GetDtd() const { return wxSVG_FONT_ELEMENT; }
};

#endif // WX_SVG_FONT_ELEMENT_H