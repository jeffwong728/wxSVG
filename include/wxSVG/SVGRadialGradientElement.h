//////////////////////////////////////////////////////////////////////////////
// Name:        SVGRadialGradientElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_RADIAL_GRADIENT_ELEMENT_H
#define WX_SVG_RADIAL_GRADIENT_ELEMENT_H

#include "SVGGradientElement.h"
#include "SVGAnimatedLength.h"
#include "String.h"

class wxSVGRadialGradientElement:
  public wxSVGGradientElement
{
  protected:
	wxSVGAnimatedLength m_cx;
	wxSVGAnimatedLength m_cy;
	wxSVGAnimatedLength m_r;
	wxSVGAnimatedLength m_fx;
	wxSVGAnimatedLength m_fy;

  public:
	inline wxSVGLength& GetCx() { return m_cx.GetBaseVal(); }
	inline void SetCx(const wxSVGLength& n) { m_cx.GetBaseVal() = n; }

	inline wxSVGLength& GetCy() { return m_cy.GetBaseVal(); }
	inline void SetCy(const wxSVGLength& n) { m_cy.GetBaseVal() = n; }

	inline wxSVGLength& GetR() { return m_r.GetBaseVal(); }
	inline void SetR(const wxSVGLength& n) { m_r.GetBaseVal() = n; }

	inline wxSVGLength& GetFx() { return m_fx.GetBaseVal(); }
	inline void SetFx(const wxSVGLength& n) { m_fx.GetBaseVal() = n; }

	inline wxSVGLength& GetFy() { return m_fy.GetBaseVal(); }
	inline void SetFy(const wxSVGLength& n) { m_fy.GetBaseVal() = n; }

  public:
	inline wxSVGLength& GetAnimatedCx() { return m_cx.GetAnimVal(); }
	inline void SetAnimatedCx(const wxSVGLength& n) { m_cx.GetAnimVal() = n; }

	inline wxSVGLength& GetAnimatedCy() { return m_cy.GetAnimVal(); }
	inline void SetAnimatedCy(const wxSVGLength& n) { m_cy.GetAnimVal() = n; }

	inline wxSVGLength& GetAnimatedR() { return m_r.GetAnimVal(); }
	inline void SetAnimatedR(const wxSVGLength& n) { m_r.GetAnimVal() = n; }

	inline wxSVGLength& GetAnimatedFx() { return m_fx.GetAnimVal(); }
	inline void SetAnimatedFx(const wxSVGLength& n) { m_fx.GetAnimVal() = n; }

	inline wxSVGLength& GetAnimatedFy() { return m_fy.GetAnimVal(); }
	inline void SetAnimatedFy(const wxSVGLength& n) { m_fy.GetAnimVal() = n; }

  public:
	wxSVGRadialGradientElement(wxSVGDocument* doc, wxString tagName = wxT("radialGradient")):
	  wxSVGGradientElement(doc, tagName) {}
	virtual ~wxSVGRadialGradientElement() {}
	bool SetAttribute(const wxString& name, const wxString& value);
	virtual const wxSVGDTD GetDtd() const { return wxSVG_RADIALGRADIENT_ELEMENT; }
};

#endif // WX_SVG_RADIAL_GRADIENT_ELEMENT_H