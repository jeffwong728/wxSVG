//////////////////////////////////////////////////////////////////////////////
// Name:        SVGAnimatedNumber.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by genAnimated.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ANIMATED_NUMBER_H
#define WX_SVG_ANIMATED_NUMBER_H


class wxSVGAnimatedNumber
{
  public:
    wxSVGAnimatedNumber(): m_baseVal(0), m_animVal(0) {}
	wxSVGAnimatedNumber(float value): m_baseVal(value), m_animVal(value) {}
	
    inline float GetBaseVal() const { return m_baseVal; };
	inline void SetBaseVal(float value) { m_baseVal = m_animVal = value; }
	
    inline float GetAnimVal() const { return m_animVal; }
	inline void SetAnimVal(float value) { m_animVal = value; }
    
  public:
    inline operator float() const { return GetBaseVal(); }
    
  protected:
    float m_baseVal;
    float m_animVal;
};


#endif // WX_SVG_ANIMATED_NUMBER_H
