//////////////////////////////////////////////////////////////////////////////
// Name:        SVGElementInstance.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ELEMENT_INSTANCE_H
#define WX_SVG_ELEMENT_INSTANCE_H

class wxSVGElement;
class wxSVGUseElement;
class wxSVGElementInstance;
class wxSVGElementInstanceList;
class wxSVGElementInstance;
class wxSVGElementInstance;
class wxSVGElementInstance;
class wxSVGElementInstance;

#include "EventTarget.h"

class wxSVGElementInstance:
  public wxEventTarget
{
  protected:
	wxSVGElement* m_correspondingElement;
	wxSVGUseElement* m_correspondingUseElement;
	wxSVGElementInstance* m_parentNode;
	wxSVGElementInstanceList* m_childNodes;
	wxSVGElementInstance* m_firstChild;
	wxSVGElementInstance* m_lastChild;
	wxSVGElementInstance* m_previousSibling;
	wxSVGElementInstance* m_nextSibling;

  public:
	inline wxSVGElement* GetCorrespondingElement() { return m_correspondingElement; }
	inline void SetCorrespondingElement(wxSVGElement* n) { m_correspondingElement = n; }

	inline wxSVGUseElement* GetCorrespondingUseElement() { return m_correspondingUseElement; }
	inline void SetCorrespondingUseElement(wxSVGUseElement* n) { m_correspondingUseElement = n; }

	inline wxSVGElementInstance* GetParentNode() { return m_parentNode; }
	inline void SetParentNode(wxSVGElementInstance* n) { m_parentNode = n; }

	inline wxSVGElementInstanceList* GetChildNodes() { return m_childNodes; }
	inline void SetChildNodes(wxSVGElementInstanceList* n) { m_childNodes = n; }

	inline wxSVGElementInstance* GetFirstChild() { return m_firstChild; }
	inline void SetFirstChild(wxSVGElementInstance* n) { m_firstChild = n; }

	inline wxSVGElementInstance* GetLastChild() { return m_lastChild; }
	inline void SetLastChild(wxSVGElementInstance* n) { m_lastChild = n; }

	inline wxSVGElementInstance* GetPreviousSibling() { return m_previousSibling; }
	inline void SetPreviousSibling(wxSVGElementInstance* n) { m_previousSibling = n; }

	inline wxSVGElementInstance* GetNextSibling() { return m_nextSibling; }
	inline void SetNextSibling(wxSVGElementInstance* n) { m_nextSibling = n; }

  public:
	wxSVGElementInstance() {}
	virtual ~wxSVGElementInstance() {}
};

#endif // WX_SVG_ELEMENT_INSTANCE_H