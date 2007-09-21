//////////////////////////////////////////////////////////////////////////////
// Name:        SVGAnimatedPoints.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ANIMATED_POINTS_H
#define WX_SVG_ANIMATED_POINTS_H

#include "SVGPointList.h"
#include "String_wxsvg.h"
#include "Element.h"

class wxSVGAnimatedPoints
{
  protected:
    wxSVGPointList m_points;
    wxSVGPointList m_animatedPoints;

  public:
    inline const wxSVGPointList& GetPoints() const { return m_points; }
    inline void SetPoints(const wxSVGPointList& n) { m_points = n; }

    inline const wxSVGPointList& GetAnimatedPoints() const { return m_animatedPoints; }
    inline void SetAnimatedPoints(const wxSVGPointList& n) { m_animatedPoints = n; }

  public:
    virtual ~wxSVGAnimatedPoints() {}
    bool HasAttribute(const wxString& name);
    wxString GetAttribute(const wxString& name);
    bool SetAttribute(const wxString& name, const wxString& value);
    wxSvgXmlAttrHash GetAttributes() const;
};

#endif // WX_SVG_ANIMATED_POINTS_H
