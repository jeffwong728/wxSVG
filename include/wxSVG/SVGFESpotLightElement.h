//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFESpotLightElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FE_SPOT_LIGHT_ELEMENT_H
#define WX_SVG_FE_SPOT_LIGHT_ELEMENT_H

#include "SVGElement.h"
#include "SVGAnimatedNumber.h"
#include "String.h"

class wxSVGFESpotLightElement:
  public wxSVGElement
{
  protected:
    wxSVGAnimatedNumber m_x;
    wxSVGAnimatedNumber m_y;
    wxSVGAnimatedNumber m_z;
    wxSVGAnimatedNumber m_pointsAtX;
    wxSVGAnimatedNumber m_pointsAtY;
    wxSVGAnimatedNumber m_pointsAtZ;
    wxSVGAnimatedNumber m_specularExponent;
    wxSVGAnimatedNumber m_limitingConeAngle;

  public:
    inline const wxSVGAnimatedNumber& GetX() const { return m_x; }
    inline void SetX(const wxSVGAnimatedNumber& n) { m_x = n; }
    inline void SetX(float n) { m_x.SetBaseVal(n); }

    inline const wxSVGAnimatedNumber& GetY() const { return m_y; }
    inline void SetY(const wxSVGAnimatedNumber& n) { m_y = n; }
    inline void SetY(float n) { m_y.SetBaseVal(n); }

    inline const wxSVGAnimatedNumber& GetZ() const { return m_z; }
    inline void SetZ(const wxSVGAnimatedNumber& n) { m_z = n; }
    inline void SetZ(float n) { m_z.SetBaseVal(n); }

    inline const wxSVGAnimatedNumber& GetPointsAtX() const { return m_pointsAtX; }
    inline void SetPointsAtX(const wxSVGAnimatedNumber& n) { m_pointsAtX = n; }
    inline void SetPointsAtX(float n) { m_pointsAtX.SetBaseVal(n); }

    inline const wxSVGAnimatedNumber& GetPointsAtY() const { return m_pointsAtY; }
    inline void SetPointsAtY(const wxSVGAnimatedNumber& n) { m_pointsAtY = n; }
    inline void SetPointsAtY(float n) { m_pointsAtY.SetBaseVal(n); }

    inline const wxSVGAnimatedNumber& GetPointsAtZ() const { return m_pointsAtZ; }
    inline void SetPointsAtZ(const wxSVGAnimatedNumber& n) { m_pointsAtZ = n; }
    inline void SetPointsAtZ(float n) { m_pointsAtZ.SetBaseVal(n); }

    inline const wxSVGAnimatedNumber& GetSpecularExponent() const { return m_specularExponent; }
    inline void SetSpecularExponent(const wxSVGAnimatedNumber& n) { m_specularExponent = n; }
    inline void SetSpecularExponent(float n) { m_specularExponent.SetBaseVal(n); }

    inline const wxSVGAnimatedNumber& GetLimitingConeAngle() const { return m_limitingConeAngle; }
    inline void SetLimitingConeAngle(const wxSVGAnimatedNumber& n) { m_limitingConeAngle = n; }
    inline void SetLimitingConeAngle(float n) { m_limitingConeAngle.SetBaseVal(n); }

  public:
    wxSVGFESpotLightElement(wxString tagName = wxT("feSpotLight")):
      wxSVGElement(tagName) {}
    virtual ~wxSVGFESpotLightElement() {}
    wxXmlNode* CloneNode(bool deep = true) { return new wxSVGFESpotLightElement(*this); }
    bool HasAttribute(const wxString& name);
    wxString GetAttribute(const wxString& name);
    bool SetAttribute(const wxString& name, const wxString& value);
    virtual const wxSVGDTD GetDtd() const { return wxSVG_FESPOTLIGHT_ELEMENT; }
};

#endif // WX_SVG_FE_SPOT_LIGHT_ELEMENT_H
