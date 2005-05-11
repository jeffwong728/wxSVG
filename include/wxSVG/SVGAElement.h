//////////////////////////////////////////////////////////////////////////////
// Name:        SVGAElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_A_ELEMENT_H
#define WX_SVG_A_ELEMENT_H

#include "SVGElement.h"
#include "SVGURIReference.h"
#include "SVGTests.h"
#include "SVGLangSpace.h"
#include "SVGExternalResourcesRequired.h"
#include "SVGStylable.h"
#include "SVGTransformable.h"
#include "EventTarget.h"
#include "SVGAnimatedString.h"
#include "String.h"

class wxSVGAElement:
  public wxSVGElement,
  public wxSVGURIReference,
  public wxSVGTests,
  public wxSVGLangSpace,
  public wxSVGExternalResourcesRequired,
  public wxSVGStylable,
  public wxSVGTransformable,
  public wxEventTarget
{
  protected:
	wxSVGAnimatedString m_target;

  public:
	inline wxString GetTarget() const { return m_target.GetBaseVal(); }
	inline void SetTarget(const wxString& n) { m_target.GetBaseVal() = n; }

  public:
	inline wxString GetAnimatedTarget() const { return m_target.GetAnimVal(); }
	inline void SetAnimatedTarget(const wxString& n) { m_target.GetAnimVal() = n; }

  public:
	wxSVGAElement(wxSVGDocument* doc, wxString tagName = wxT("a")):
	  wxSVGElement(doc, tagName) {}
	virtual ~wxSVGAElement() {}
	virtual wxSVGRect GetBBox() { return wxSVGLocatable::GetBBox(this); }
	bool SetAttribute(const wxString& name, const wxString& value);
	virtual const wxSVGDTD GetDtd() const { return wxSVG_A_ELEMENT; }
};

#endif // WX_SVG_A_ELEMENT_H
