//////////////////////////////////////////////////////////////////////////////
// Name:        SVGExternalResourcesRequired.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_EXTERNAL_RESOURCES_REQUIRED_H
#define WX_SVG_EXTERNAL_RESOURCES_REQUIRED_H

#include "SVGAnimatedBoolean.h"
#include "String.h"

class wxSVGExternalResourcesRequired
{
  protected:
	wxSVGAnimatedBoolean m_externalResourcesRequired;

  public:
	inline bool GetExternalResourcesRequired() const { return m_externalResourcesRequired.GetBaseVal(); }
	inline void SetExternalResourcesRequired(const bool n) { m_externalResourcesRequired.GetBaseVal() = n; }

  public:
	inline bool GetAnimatedExternalResourcesRequired() const { return m_externalResourcesRequired.GetAnimVal(); }
	inline void SetAnimatedExternalResourcesRequired(const bool n) { m_externalResourcesRequired.GetAnimVal() = n; }

  public:
	virtual ~wxSVGExternalResourcesRequired() {}
	bool SetAttribute(const wxString& name, const wxString& value);
};

#endif // WX_SVG_EXTERNAL_RESOURCES_REQUIRED_H