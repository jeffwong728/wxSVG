//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFEGaussianBlurElement.cpp
// Purpose:     
// Author:      Alex Thuering
// Created:     2005/05/10
// RCS-ID:      $Id: SVGFEGaussianBlurElement.cpp,v 1.1.1.1 2005-05-10 17:51:39 ntalex Exp $
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
//////////////////////////////////////////////////////////////////////////////

#include "SVGFEGaussianBlurElement.h"

void wxSVGFEGaussianBlurElement::SetStdDeviation(float stdDeviationX, float stdDeviationY)
{
  SetStdDeviationX(stdDeviationX);
  SetStdDeviationY(stdDeviationY);
}
