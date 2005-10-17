//////////////////////////////////////////////////////////////////////////////
// Name:        SVGViewElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_VIEW_ELEMENT_H
#define WX_SVG_VIEW_ELEMENT_H

#include "SVGElement.h"
#include "SVGExternalResourcesRequired.h"
#include "SVGFitToViewBox.h"
#include "SVGZoomAndPan.h"
#include "SVGStringList.h"
#include "String.h"

class wxSVGViewElement:
  public wxSVGElement,
  public wxSVGExternalResourcesRequired,
  public wxSVGFitToViewBox,
  public wxSVGZoomAndPan
{
  protected:
    wxSVGStringList m_viewTarget;

  public:
    inline const wxSVGStringList& GetViewTarget() const { return m_viewTarget; }
    inline void SetViewTarget(const wxSVGStringList& n) { m_viewTarget = n; }

  public:
    wxSVGViewElement(wxString tagName = wxT("view")):
      wxSVGElement(tagName) {}
    virtual ~wxSVGViewElement() {}
    wxXmlNode* CloneNode(bool deep = true) { return new wxSVGViewElement(*this); }
    bool HasAttribute(const wxString& name);
    wxString GetAttribute(const wxString& name);
    bool SetAttribute(const wxString& name, const wxString& value);
    virtual const wxSVGDTD GetDtd() const { return wxSVG_VIEW_ELEMENT; }
};

#endif // WX_SVG_VIEW_ELEMENT_H
