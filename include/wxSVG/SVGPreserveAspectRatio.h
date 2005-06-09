//////////////////////////////////////////////////////////////////////////////
// Name:        SVGPreserveAspectRatio.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_PRESERVE_ASPECT_RATIO_H
#define WX_SVG_PRESERVE_ASPECT_RATIO_H


enum wxSVG_PRESERVEASPECTRATIO
{
  wxSVG_PRESERVEASPECTRATIO_UNKNOWN = 0,
  wxSVG_PRESERVEASPECTRATIO_NONE = 1,
  wxSVG_PRESERVEASPECTRATIO_XMINYMIN = 2,
  wxSVG_PRESERVEASPECTRATIO_XMIDYMIN = 3,
  wxSVG_PRESERVEASPECTRATIO_XMAXYMIN = 4,
  wxSVG_PRESERVEASPECTRATIO_XMINYMID = 5,
  wxSVG_PRESERVEASPECTRATIO_XMIDYMID = 6,
  wxSVG_PRESERVEASPECTRATIO_XMAXYMID = 7,
  wxSVG_PRESERVEASPECTRATIO_XMINYMAX = 8,
  wxSVG_PRESERVEASPECTRATIO_XMIDYMAX = 9,
  wxSVG_PRESERVEASPECTRATIO_XMAXYMAX = 10
};


enum wxSVG_MEETORSLICE
{
  wxSVG_MEETORSLICE_UNKNOWN = 0,
  wxSVG_MEETORSLICE_MEET = 1,
  wxSVG_MEETORSLICE_SLICE = 2
};

class wxSVGPreserveAspectRatio
{
  protected:
    wxSVG_PRESERVEASPECTRATIO m_align;
    wxSVG_MEETORSLICE m_meetOrSlice;

  public:
    inline wxSVG_PRESERVEASPECTRATIO GetAlign() const { return m_align; }
    inline void SetAlign(const wxSVG_PRESERVEASPECTRATIO& n) { m_align = n; }

    inline wxSVG_MEETORSLICE GetMeetOrSlice() const { return m_meetOrSlice; }
    inline void SetMeetOrSlice(const wxSVG_MEETORSLICE& n) { m_meetOrSlice = n; }

  public:
    wxSVGPreserveAspectRatio(): m_align(wxSVG_PRESERVEASPECTRATIO(0)), m_meetOrSlice(wxSVG_MEETORSLICE(0)) {}
    virtual ~wxSVGPreserveAspectRatio() {}
};

#endif // WX_SVG_PRESERVE_ASPECT_RATIO_H
