//////////////////////////////////////////////////////////////////////////////
// Name:        SVGPathSegLinetoVerticalAbs.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_PATH_SEG_LINETO_VERTICAL_ABS_H
#define WX_SVG_PATH_SEG_LINETO_VERTICAL_ABS_H

#include "SVGPathSeg.h"

class wxSVGPathSegLinetoVerticalAbs:
  public wxSVGPathSeg
{
  protected:
    float m_y;

  public:
    inline float GetY() const { return m_y; }
    inline void SetY(const float n) { m_y = n; }

  public:
    wxSVGPathSegLinetoVerticalAbs():
      wxSVGPathSeg(wxPATHSEG_LINETO_VERTICAL_ABS), m_y(0) {}
    virtual ~wxSVGPathSegLinetoVerticalAbs() {}
};

#endif // WX_SVG_PATH_SEG_LINETO_VERTICAL_ABS_H
