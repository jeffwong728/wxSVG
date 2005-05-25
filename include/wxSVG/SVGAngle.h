//////////////////////////////////////////////////////////////////////////////
// Name:        SVGAngle.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ANGLE_H
#define WX_SVG_ANGLE_H

#include "String.h"

class wxSVGAngle
{
  public:

	enum wxSVG_ANGLETYPE
	{
	  wxSVG_ANGLETYPE_UNKNOWN = 0,
	  wxSVG_ANGLETYPE_UNSPECIFIED = 1,
	  wxSVG_ANGLETYPE_DEG = 2,
	  wxSVG_ANGLETYPE_RAD = 3,
	  wxSVG_ANGLETYPE_GRAD = 4
	};

  protected:
	wxSVG_ANGLETYPE m_unitType;
	float m_value;

  public:
	inline wxSVG_ANGLETYPE GetUnitType() const { return m_unitType; }
	inline void SetUnitType(const wxSVG_ANGLETYPE& n) { m_unitType = n; }

	inline float GetValue() const { return m_value; }
	inline void SetValue(const float n) { m_value = n; }

	float GetValueInSpecifiedUnits() const;
	void SetValueInSpecifiedUnits(const float n);

	wxString GetValueAsString() const;
	void SetValueAsString(const wxString& n);

  public:
	wxSVGAngle() : m_unitType(wxSVG_ANGLETYPE_UNKNOWN), m_value(0) {}
	wxSVGAngle(float v) : m_unitType(wxSVG_ANGLETYPE_DEG), m_value(v) {}
	virtual ~wxSVGAngle() {}
	inline operator float() { return GetValue(); }
	virtual void NewValueSpecifiedUnits(wxSVG_ANGLETYPE unitType, float valueInSpecifiedUnits);
	virtual void ConvertToSpecifiedUnits(wxSVG_ANGLETYPE unitType);
};

#endif // WX_SVG_ANGLE_H