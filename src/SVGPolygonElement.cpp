//////////////////////////////////////////////////////////////////////////////
// Name:        SVGPolygonElement.cpp
// Purpose:     
// Author:      Alex Thuering
// Created:     2005/05/10
// RCS-ID:      $Id: SVGPolygonElement.cpp,v 1.1.1.1 2005-05-10 17:51:39 ntalex Exp $
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
//////////////////////////////////////////////////////////////////////////////

#include "SVGPolygonElement.h"

wxSVGRect wxSVGPolygonElement::GetBBox()
{
  wxSVGPointList& points = GetPoints();
  if (points.Count() == 0)
	return wxSVGRect();
  
  wxSVGRect bbox(points[0].GetX(), points[0].GetY(), 0, 0);
  
  for (int i = 1; i<(int)points.Count(); i++)
  {
	if (bbox.GetX() > points[i].GetX())
	{
	  bbox.SetWidth(bbox.GetWidth() + bbox.GetX() - points[i].GetX());
	  bbox.SetX(points[i].GetX());
	}
	if (bbox.GetY() > points[i].GetY())
	{
	  bbox.SetHeight(bbox.GetHeight() + bbox.GetY() - points[i].GetY());
	  bbox.SetY(points[i].GetY());
	}
	
	if (bbox.GetX() + bbox.GetWidth() < points[i].GetX())
	  bbox.SetWidth(points[i].GetX() - bbox.GetX());
	if (bbox.GetY() + bbox.GetHeight() < points[i].GetY())
	  bbox.SetHeight(points[i].GetY() - bbox.GetY());
  }
  
  return bbox;
}
