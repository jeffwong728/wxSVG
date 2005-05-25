//////////////////////////////////////////////////////////////////////////////
// Name:        svgctrl.cpp
// Purpose:     svg control widget
// Author:      Alex Thuering
// Created:     2005/05/07
// RCS-ID:      $Id: svgctrl.cpp,v 1.1.1.1 2005-05-10 17:51:39 ntalex Exp $
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
//////////////////////////////////////////////////////////////////////////////

#include "svgctrl.h"
#include <wx/wx.h>

BEGIN_EVENT_TABLE(wxSVGCtrl, wxControl)
   EVT_PAINT(wxSVGCtrl::OnPaint) 
   EVT_SIZE(wxSVGCtrl::OnResize)
END_EVENT_TABLE()

wxSVGCtrl::wxSVGCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos,
 const wxSize& size, long style, const wxValidator& validator, const wxString& name):
  wxControl(parent, id, pos, size, style, validator, name)
{
  m_doc = NULL;
  m_docDelete = false;
}

void wxSVGCtrl::SetSVG(wxSVGDocument* doc)
{
  if (m_doc && m_docDelete)
    delete m_doc;
  m_doc = doc;
}

bool wxSVGCtrl::Load(const wxString& filename)
{
  if (!m_doc)
  {
    m_doc = new wxSVGDocument;
    m_docDelete = true;
  }
  
  if (!m_doc->Load(filename))
    return false;
  
  Update();
  return true;
}

void wxSVGCtrl::Update()
{
  if (!m_doc)
    return;
  int w, h;
  GetClientSize(&w, &h);
  m_buffer = wxBitmap(m_doc->Render(w, h));
  Refresh();
}

void wxSVGCtrl::OnPaint(wxPaintEvent& event)
{
  if (!m_buffer.Ok())
    return;
  wxPaintDC dc(this);
  dc.DrawBitmap(m_buffer, 0, 0);
}