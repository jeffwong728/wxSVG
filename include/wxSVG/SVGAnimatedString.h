//////////////////////////////////////////////////////////////////////////////
// Name:        SVGAnimatedString.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by genAnimated.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ANIMATED_STRING_H
#define WX_SVG_ANIMATED_STRING_H

#include "String_wxsvg.h"

class wxSVGAnimatedString
{
  public:
    wxSVGAnimatedString(): m_animVal(NULL) {}
    wxSVGAnimatedString(const wxString& value): m_baseVal(value), m_animVal(NULL) {}
    wxSVGAnimatedString(const wxSVGAnimatedString& value): m_baseVal(value.m_baseVal), m_animVal(NULL)
    { if (value.m_animVal != NULL) m_animVal = new wxString(*value.m_animVal); }
    ~wxSVGAnimatedString() { ResetAnimVal(); }
    
    inline wxSVGAnimatedString& operator=(const wxSVGAnimatedString& value)
    { m_baseVal = value.m_baseVal; m_animVal = value.m_animVal != NULL ? new wxString(*value.m_animVal) : NULL; return *this; }
    
    inline wxString& GetBaseVal() { return m_baseVal; }
    inline const wxString& GetBaseVal() const { return m_baseVal; }
    inline void SetBaseVal(const wxString& value) { m_baseVal = value; ResetAnimVal(); }
    
    inline wxString& GetAnimVal()
    {
      if (!m_animVal)
        m_animVal = new wxString(m_baseVal);
      return *m_animVal;
    }
    inline const wxString& GetAnimVal() const
    {
        return m_animVal ? *m_animVal : m_baseVal;
    }
    inline void SetAnimVal(const wxString& value)
    {
      if (!m_animVal)
        m_animVal = new wxString(value);
      else
        *m_animVal = value;
    }
    inline void ResetAnimVal()
    {
      if (m_animVal)
      {
        delete m_animVal;
        m_animVal = NULL;
      }
    }
    
  public:
    inline operator const wxString&() const { return GetAnimVal(); }
    
  protected:
    wxString m_baseVal;
    wxString* m_animVal;
};


#endif // WX_SVG_ANIMATED_STRING_H
