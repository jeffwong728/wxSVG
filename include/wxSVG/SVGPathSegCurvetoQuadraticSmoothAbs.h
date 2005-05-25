//////////////////////////////////////////////////////////////////////////////
// Name:        SVGPathSegCurvetoQuadraticSmoothAbs.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_PATH_SEG_CURVETO_QUADRATIC_SMOOTH_ABS_H
#define WX_SVG_PATH_SEG_CURVETO_QUADRATIC_SMOOTH_ABS_H

#include "SVGPathSeg.h"

class wxSVGPathSegCurvetoQuadraticSmoothAbs:
  public wxSVGPathSeg
{
  protected:
	float m_x;
	float m_y;

  public:
	inline float GetX() const { return m_x; }
	inline void SetX(const float n) { m_x = n; }

	inline float GetY() const { return m_y; }
	inline void SetY(const float n) { m_y = n; }

  public:
	wxSVGPathSegCurvetoQuadraticSmoothAbs():
	  wxSVGPathSeg(wxPATHSEG_CURVETO_QUADRATIC_SMOOTH_ABS), m_x(0), m_y(0) {}
	virtual ~wxSVGPathSegCurvetoQuadraticSmoothAbs() {}
};

#endif // WX_SVG_PATH_SEG_CURVETO_QUADRATIC_SMOOTH_ABS_H