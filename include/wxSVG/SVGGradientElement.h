//////////////////////////////////////////////////////////////////////////////
// Name:        SVGGradientElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_GRADIENT_ELEMENT_H
#define WX_SVG_GRADIENT_ELEMENT_H

#include "SVGElement.h"
#include "SVGURIReference.h"
#include "SVGExternalResourcesRequired.h"
#include "SVGStylable.h"
#include "SVGUnitTypes.h"
#include "SVGAnimatedEnumeration.h"
#include "SVGAnimatedTransformList.h"
#include "String.h"


enum wxSVG_SPREADMETHOD
{
  wxSVG_SPREADMETHOD_UNKNOWN = 0,
  wxSVG_SPREADMETHOD_PAD = 1,
  wxSVG_SPREADMETHOD_REFLECT = 2,
  wxSVG_SPREADMETHOD_REPEAT = 3
};

class wxSVGGradientElement:
  public wxSVGElement,
  public wxSVGURIReference,
  public wxSVGExternalResourcesRequired,
  public wxSVGStylable,
  public wxSVGUnitTypes
{
  protected:
    wxSVGAnimatedEnumeration m_gradientUnits;
    wxSVGAnimatedTransformList m_gradientTransform;
    wxSVGAnimatedEnumeration m_spreadMethod;

  public:
    inline char GetGradientUnits() const { return m_gradientUnits.GetBaseVal(); }
    inline void SetGradientUnits(const char n) { m_gradientUnits.GetBaseVal() = n; }

    inline wxSVGTransformList& GetGradientTransform() { return m_gradientTransform.GetBaseVal(); }
    inline void SetGradientTransform(const wxSVGTransformList& n) { m_gradientTransform.GetBaseVal() = n; }

    inline char GetSpreadMethod() const { return m_spreadMethod.GetBaseVal(); }
    inline void SetSpreadMethod(const char n) { m_spreadMethod.GetBaseVal() = n; }

  public:
    inline char GetAnimatedGradientUnits() const { return m_gradientUnits.GetAnimVal(); }
    inline void SetAnimatedGradientUnits(const char n) { m_gradientUnits.GetAnimVal() = n; }

    inline wxSVGTransformList& GetAnimatedGradientTransform() { return m_gradientTransform.GetAnimVal(); }
    inline void SetAnimatedGradientTransform(const wxSVGTransformList& n) { m_gradientTransform.GetAnimVal() = n; }

    inline char GetAnimatedSpreadMethod() const { return m_spreadMethod.GetAnimVal(); }
    inline void SetAnimatedSpreadMethod(const char n) { m_spreadMethod.GetAnimVal() = n; }

  public:
    wxSVGGradientElement(wxSVGDocument* doc, wxString tagName = wxT("")):
      wxSVGElement(doc, tagName) {}
    virtual ~wxSVGGradientElement() {}
    bool SetAttribute(const wxString& name, const wxString& value);
};

#endif // WX_SVG_GRADIENT_ELEMENT_H
