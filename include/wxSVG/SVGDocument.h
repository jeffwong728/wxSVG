//////////////////////////////////////////////////////////////////////////////
// Name:        SVGDocument.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_DOCUMENT_H
#define WX_SVG_DOCUMENT_H

class wxSVGSVGElement;
class wxSVGElement;
class wxSVGCanvas;

#include "Document.h"
#include "DocumentEvent.h"
#include "String.h"
#include <wx/image.h>

class wxSVGDocument:
  public wxXmlDocument,
  public wxDocumentEvent
{
  protected:
    wxString m_title;
    wxString m_referrer;
    wxString m_domain;
    wxString m_URL;

  public:
    inline const wxString& GetTitle() { return m_title; }
    inline void SetTitle(const wxString& n) { m_title = n; }

    inline const wxString& GetReferrer() { return m_referrer; }
    inline void SetReferrer(const wxString& n) { m_referrer = n; }

    inline const wxString& GetDomain() { return m_domain; }
    inline void SetDomain(const wxString& n) { m_domain = n; }

    inline const wxString& GetURL() { return m_URL; }
    inline void SetURL(const wxString& n) { m_URL = n; }


  protected:
	wxSVGCanvas* m_canvas;

  public:
    wxSVGDocument() { Init(); }
	wxSVGDocument(const wxString& filename, const wxString& encoding = wxT("UTF-8")):
	  wxXmlDocument(filename, encoding) { Init(); }
	wxSVGDocument(wxInputStream& stream, const wxString& encoding = wxT("UTF-8")):
	  wxXmlDocument(stream, encoding) { Init(); }
	virtual ~wxSVGDocument();
	
	void Init();
	inline wxSVGCanvas* GetCanvas() { return m_canvas; }
	
	wxXmlElement* CreateElement(const wxString& tagName);
	wxXmlElement* CreateElementNS(const wxString& namespaceURI, const wxString& qualifiedName);
	
	wxSVGSVGElement* GetRootElement() { return (wxSVGSVGElement*) GetRoot(); }
	void SetRootElement(wxSVGSVGElement* n) { SetRoot((wxXmlElement*) n); }
	
	wxImage Render(int width = -1, int height = -1);
};

#endif // WX_SVG_DOCUMENT_H
