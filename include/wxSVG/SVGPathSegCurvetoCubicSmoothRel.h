//////////////////////////////////////////////////////////////////////////////
// Name:        SVGPathSegCurvetoCubicSmoothRel.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_PATH_SEG_CURVETO_CUBIC_SMOOTH_REL_H
#define WX_SVG_PATH_SEG_CURVETO_CUBIC_SMOOTH_REL_H

#include "SVGPathSeg.h"

class wxSVGPathSegCurvetoCubicSmoothRel:
  public wxSVGPathSeg
{
  protected:
	float m_x;
	float m_y;
	float m_x2;
	float m_y2;

  public:
	inline float GetX() const { return m_x; }
	inline void SetX(const float n) { m_x = n; }

	inline float GetY() const { return m_y; }
	inline void SetY(const float n) { m_y = n; }

	inline float GetX2() const { return m_x2; }
	inline void SetX2(const float n) { m_x2 = n; }

	inline float GetY2() const { return m_y2; }
	inline void SetY2(const float n) { m_y2 = n; }

  public:
	wxSVGPathSegCurvetoCubicSmoothRel():
	  wxSVGPathSeg(wxPATHSEG_CURVETO_CUBIC_SMOOTH_REL), m_x(0), m_y(0), m_x2(0), m_y2(0) {}
	virtual ~wxSVGPathSegCurvetoCubicSmoothRel() {}
};

#endif // WX_SVG_PATH_SEG_CURVETO_CUBIC_SMOOTH_REL_H