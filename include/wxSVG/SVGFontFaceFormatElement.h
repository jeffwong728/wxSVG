//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFontFaceFormatElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FONT_FACE_FORMAT_ELEMENT_H
#define WX_SVG_FONT_FACE_FORMAT_ELEMENT_H

#include "SVGElement.h"
#include "String.h"

class wxSVGFontFaceFormatElement:
  public wxSVGElement
{
  public:
    wxSVGFontFaceFormatElement(wxSVGDocument* doc, wxString tagName = wxT("font-face-format")):
      wxSVGElement(doc, tagName) {}
    virtual ~wxSVGFontFaceFormatElement() {}
    bool SetAttribute(const wxString& name, const wxString& value);
    virtual const wxSVGDTD GetDtd() const { return wxSVG_FONT_FACE_FORMAT_ELEMENT; }
};

#endif // WX_SVG_FONT_FACE_FORMAT_ELEMENT_H
