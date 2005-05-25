//////////////////////////////////////////////////////////////////////////////
// Name:        SVGZoomEvent.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ZOOM_EVENT_H
#define WX_SVG_ZOOM_EVENT_H

#include "UIEvent.h"
#include "SVGRect.h"
#include "SVGPoint.h"

class wxSVGZoomEvent:
  public wxUIEvent
{
  protected:
	wxSVGRect m_zoomRectScreen;
	float m_previousScale;
	wxSVGPoint m_previousTranslate;
	float m_newScale;
	wxSVGPoint m_newTranslate;

  public:
	inline wxSVGRect& GetZoomRectScreen() { return m_zoomRectScreen; }
	inline void SetZoomRectScreen(const wxSVGRect& n) { m_zoomRectScreen = n; }

	inline float GetPreviousScale() const { return m_previousScale; }
	inline void SetPreviousScale(const float n) { m_previousScale = n; }

	inline wxSVGPoint& GetPreviousTranslate() { return m_previousTranslate; }
	inline void SetPreviousTranslate(const wxSVGPoint& n) { m_previousTranslate = n; }

	inline float GetNewScale() const { return m_newScale; }
	inline void SetNewScale(const float n) { m_newScale = n; }

	inline wxSVGPoint& GetNewTranslate() { return m_newTranslate; }
	inline void SetNewTranslate(const wxSVGPoint& n) { m_newTranslate = n; }

  public:
	wxSVGZoomEvent(): m_previousScale(0), m_newScale(0) {}
	virtual ~wxSVGZoomEvent() {}
};

#endif // WX_SVG_ZOOM_EVENT_H