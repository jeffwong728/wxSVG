//////////////////////////////////////////////////////////////////////////////
// Name:        SVGSVGElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_SVG_ELEMENT_H
#define WX_SVG_SVG_ELEMENT_H

#include "SVGElement.h"
#include "SVGTests.h"
#include "SVGLangSpace.h"
#include "SVGExternalResourcesRequired.h"
#include "SVGStylable.h"
#include "SVGLocatable.h"
#include "SVGFitToViewBox.h"
#include "SVGZoomAndPan.h"
#include "EventTarget.h"
#include "DocumentEvent.h"
#include "ViewCSS.h"
#include "DocumentCSS.h"
#include "SVGAnimatedLength.h"
#include "String.h"
#include "SVGRect.h"
#include "SVGViewSpec.h"
#include "SVGPoint.h"
#include "NodeList.h"
#include "SVGNumber.h"
#include "SVGLength.h"
#include "SVGAngle.h"
#include "SVGMatrix.h"
#include "SVGTransform.h"
#include "Element.h"

class wxSVGSVGElement:
  public wxSVGElement,
  public wxSVGTests,
  public wxSVGLangSpace,
  public wxSVGExternalResourcesRequired,
  public wxSVGStylable,
  public wxSVGLocatable,
  public wxSVGFitToViewBox,
  public wxSVGZoomAndPan,
  public wxEventTarget,
  public wxDocumentEvent,
  public wxViewCSS,
  public wxDocumentCSS
{
  protected:
	wxSVGAnimatedLength m_x;
	wxSVGAnimatedLength m_y;
	wxSVGAnimatedLength m_width;
	wxSVGAnimatedLength m_height;
	wxString m_contentScriptType;
	wxString m_contentStyleType;
	wxSVGRect m_viewport;
	float m_pixelUnitToMillimeterX;
	float m_pixelUnitToMillimeterY;
	float m_screenPixelToMillimeterX;
	float m_screenPixelToMillimeterY;
	bool m_useCurrentView;
	wxSVGViewSpec m_currentView;
	float m_currentScale;
	wxSVGPoint m_currentTranslate;

  public:
	inline wxSVGLength& GetX() { return m_x.GetBaseVal(); }
	inline void SetX(const wxSVGLength& n) { m_x.GetBaseVal() = n; }

	inline wxSVGLength& GetY() { return m_y.GetBaseVal(); }
	inline void SetY(const wxSVGLength& n) { m_y.GetBaseVal() = n; }

	inline wxSVGLength& GetWidth() { return m_width.GetBaseVal(); }
	inline void SetWidth(const wxSVGLength& n) { m_width.GetBaseVal() = n; }

	inline wxSVGLength& GetHeight() { return m_height.GetBaseVal(); }
	inline void SetHeight(const wxSVGLength& n) { m_height.GetBaseVal() = n; }

	inline wxString GetContentScriptType() const { return m_contentScriptType; }
	inline void SetContentScriptType(const wxString& n) { m_contentScriptType = n; }

	inline wxString GetContentStyleType() const { return m_contentStyleType; }
	inline void SetContentStyleType(const wxString& n) { m_contentStyleType = n; }

	inline wxSVGRect& GetViewport() { return m_viewport; }
	inline void SetViewport(const wxSVGRect& n) { m_viewport = n; }

	inline float GetPixelUnitToMillimeterX() const { return m_pixelUnitToMillimeterX; }
	inline void SetPixelUnitToMillimeterX(const float n) { m_pixelUnitToMillimeterX = n; }

	inline float GetPixelUnitToMillimeterY() const { return m_pixelUnitToMillimeterY; }
	inline void SetPixelUnitToMillimeterY(const float n) { m_pixelUnitToMillimeterY = n; }

	inline float GetScreenPixelToMillimeterX() const { return m_screenPixelToMillimeterX; }
	inline void SetScreenPixelToMillimeterX(const float n) { m_screenPixelToMillimeterX = n; }

	inline float GetScreenPixelToMillimeterY() const { return m_screenPixelToMillimeterY; }
	inline void SetScreenPixelToMillimeterY(const float n) { m_screenPixelToMillimeterY = n; }

	inline bool GetUseCurrentView() const { return m_useCurrentView; }
	inline void SetUseCurrentView(const bool n) { m_useCurrentView = n; }

	inline wxSVGViewSpec& GetCurrentView() { return m_currentView; }
	inline void SetCurrentView(const wxSVGViewSpec& n) { m_currentView = n; }

	inline float GetCurrentScale() const { return m_currentScale; }
	inline void SetCurrentScale(const float n) { m_currentScale = n; }

	inline wxSVGPoint& GetCurrentTranslate() { return m_currentTranslate; }
	inline void SetCurrentTranslate(const wxSVGPoint& n) { m_currentTranslate = n; }

  public:
	wxSVGSVGElement(wxSVGDocument* doc, wxString tagName = wxT("svg")):
	  wxSVGElement(doc, tagName), m_pixelUnitToMillimeterX(0), m_pixelUnitToMillimeterY(0), m_screenPixelToMillimeterX(0), m_screenPixelToMillimeterY(0), m_useCurrentView(0), m_currentScale(0) {}
	virtual ~wxSVGSVGElement() {}
	virtual wxSVGRect GetBBox() { return wxSVGLocatable::GetBBox(this); }
	virtual unsigned long SuspendRedraw(unsigned long max_wait_milliseconds);
	virtual void UnsuspendRedraw(unsigned long suspend_handle_id);
	virtual void UnsuspendRedrawAll();
	virtual void ForceRedraw();
	virtual void PauseAnimations();
	virtual void UnpauseAnimations();
	virtual bool AnimationsPaused();
	virtual float GetCurrentTime();
	virtual void SetCurrentTime(float seconds);
	virtual wxNodeList GetIntersectionList(const wxSVGRect& rect, const wxSVGElement& referenceElement);
	virtual wxNodeList GetEnclosureList(const wxSVGRect& rect, const wxSVGElement& referenceElement);
	virtual bool CheckIntersection(const wxSVGElement& element, const wxSVGRect& rect);
	virtual bool CheckEnclosure(const wxSVGElement& element, const wxSVGRect& rect);
	virtual void DeselectAll();
	virtual wxSVGNumber CreateSVGNumber();
	virtual wxSVGLength CreateSVGLength();
	virtual wxSVGAngle CreateSVGAngle();
	virtual wxSVGPoint CreateSVGPoint();
	virtual wxSVGMatrix CreateSVGMatrix();
	virtual wxSVGRect CreateSVGRect();
	virtual wxSVGTransform CreateSVGTransform();
	virtual wxSVGTransform CreateSVGTransformFromMatrix(const wxSVGMatrix& matrix);
	virtual wxXmlElement* GetElementById(const wxString& elementId);
	bool SetAttribute(const wxString& name, const wxString& value);
	virtual const wxSVGDTD GetDtd() const { return wxSVG_SVG_ELEMENT; }
};

#endif // WX_SVG_SVG_ELEMENT_H