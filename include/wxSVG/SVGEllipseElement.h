//////////////////////////////////////////////////////////////////////////////
// Name:        SVGEllipseElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ELLIPSE_ELEMENT_H
#define WX_SVG_ELLIPSE_ELEMENT_H

class wxSVGCanvasItem;

#include "SVGElement.h"
#include "SVGTests.h"
#include "SVGLangSpace.h"
#include "SVGExternalResourcesRequired.h"
#include "SVGStylable.h"
#include "SVGTransformable.h"
#include "EventTarget.h"
#include "SVGAnimatedLength.h"
#include "SVGSVGElement.h"
#include "String.h"

class wxSVGEllipseElement:
  public wxSVGElement,
  public wxSVGTests,
  public wxSVGLangSpace,
  public wxSVGExternalResourcesRequired,
  public wxSVGStylable,
  public wxSVGTransformable,
  public wxEventTarget
{
  protected:
    wxSVGAnimatedLength m_cx;
    wxSVGAnimatedLength m_cy;
    wxSVGAnimatedLength m_rx;
    wxSVGAnimatedLength m_ry;

  public:
    inline const wxSVGAnimatedLength& GetCx() const { WX_SVG_ANIM_LENGTH_CALC_WIDTH(m_cx, GetViewportElement()); return m_cx; }
    inline void SetCx(const wxSVGAnimatedLength& n) { m_cx = n; }
    inline void SetCx(const wxSVGLength& n) { m_cx.SetBaseVal(n); }

    inline const wxSVGAnimatedLength& GetCy() const { WX_SVG_ANIM_LENGTH_CALC_HEIGHT(m_cy, GetViewportElement()); return m_cy; }
    inline void SetCy(const wxSVGAnimatedLength& n) { m_cy = n; }
    inline void SetCy(const wxSVGLength& n) { m_cy.SetBaseVal(n); }

    inline const wxSVGAnimatedLength& GetRx() const { WX_SVG_ANIM_LENGTH_CALC_WIDTH(m_rx, GetViewportElement()); return m_rx; }
    inline void SetRx(const wxSVGAnimatedLength& n) { m_rx = n; }
    inline void SetRx(const wxSVGLength& n) { m_rx.SetBaseVal(n); }

    inline const wxSVGAnimatedLength& GetRy() const { WX_SVG_ANIM_LENGTH_CALC_HEIGHT(m_ry, GetViewportElement()); return m_ry; }
    inline void SetRy(const wxSVGAnimatedLength& n) { m_ry = n; }
    inline void SetRy(const wxSVGLength& n) { m_ry.SetBaseVal(n); }


  protected:
	wxSVGCanvasItem* m_canvasItem;
  public:
	inline wxSVGCanvasItem* GetCanvasItem() { return m_canvasItem; }
	inline void SetCanvasItem(wxSVGCanvasItem* canvasItem) { m_canvasItem = canvasItem; }

  public:
    wxSVGEllipseElement(wxSVGDocument* doc, wxString tagName = wxT("ellipse")):
      wxSVGElement(doc, tagName), m_canvasItem(NULL) {}
    virtual ~wxSVGEllipseElement() {}
    wxXmlNode* CloneNode(bool deep = true) { return new wxSVGEllipseElement(*this); }
    wxSVGRect GetBBox();
    bool SetAttribute(const wxString& name, const wxString& value);
    virtual const wxSVGDTD GetDtd() const { return wxSVG_ELLIPSE_ELEMENT; }
};

#endif // WX_SVG_ELLIPSE_ELEMENT_H
