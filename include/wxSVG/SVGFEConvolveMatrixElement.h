//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFEConvolveMatrixElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FE_CONVOLVE_MATRIX_ELEMENT_H
#define WX_SVG_FE_CONVOLVE_MATRIX_ELEMENT_H

#include "SVGElement.h"
#include "SVGFilterPrimitiveStandardAttributes.h"
#include "SVGAnimatedInteger.h"
#include "SVGAnimatedNumberList.h"
#include "SVGAnimatedNumber.h"
#include "SVGAnimatedEnumeration.h"
#include "SVGAnimatedLength.h"
#include "SVGAnimatedBoolean.h"
#include "String.h"

class wxSVGFEConvolveMatrixElement:
  public wxSVGElement,
  public wxSVGFilterPrimitiveStandardAttributes
{
  public:

	enum wxSVG_EDGEMODE
	{
	  wxSVG_EDGEMODE_UNKNOWN = 0,
	  wxSVG_EDGEMODE_DUPLICATE = 1,
	  wxSVG_EDGEMODE_WRAP = 2,
	  wxSVG_EDGEMODE_NONE = 3
	};

  protected:
	wxSVGAnimatedInteger m_orderX;
	wxSVGAnimatedInteger m_orderY;
	wxSVGAnimatedNumberList m_kernelMatrix;
	wxSVGAnimatedNumber m_divisor;
	wxSVGAnimatedNumber m_bias;
	wxSVGAnimatedInteger m_targetX;
	wxSVGAnimatedInteger m_targetY;
	wxSVGAnimatedEnumeration m_edgeMode;
	wxSVGAnimatedLength m_kernelUnitLengthX;
	wxSVGAnimatedLength m_kernelUnitLengthY;
	wxSVGAnimatedBoolean m_preserveAlpha;

  public:
	inline long GetOrderX() const { return m_orderX.GetBaseVal(); }
	inline void SetOrderX(const long n) { m_orderX.GetBaseVal() = n; }

	inline long GetOrderY() const { return m_orderY.GetBaseVal(); }
	inline void SetOrderY(const long n) { m_orderY.GetBaseVal() = n; }

	inline wxSVGNumberList& GetKernelMatrix() { return m_kernelMatrix.GetBaseVal(); }
	inline void SetKernelMatrix(const wxSVGNumberList& n) { m_kernelMatrix.GetBaseVal() = n; }

	inline float GetDivisor() const { return m_divisor.GetBaseVal(); }
	inline void SetDivisor(const float n) { m_divisor.GetBaseVal() = n; }

	inline float GetBias() const { return m_bias.GetBaseVal(); }
	inline void SetBias(const float n) { m_bias.GetBaseVal() = n; }

	inline long GetTargetX() const { return m_targetX.GetBaseVal(); }
	inline void SetTargetX(const long n) { m_targetX.GetBaseVal() = n; }

	inline long GetTargetY() const { return m_targetY.GetBaseVal(); }
	inline void SetTargetY(const long n) { m_targetY.GetBaseVal() = n; }

	inline char GetEdgeMode() const { return m_edgeMode.GetBaseVal(); }
	inline void SetEdgeMode(const char n) { m_edgeMode.GetBaseVal() = n; }

	inline wxSVGLength& GetKernelUnitLengthX() { return m_kernelUnitLengthX.GetBaseVal(); }
	inline void SetKernelUnitLengthX(const wxSVGLength& n) { m_kernelUnitLengthX.GetBaseVal() = n; }

	inline wxSVGLength& GetKernelUnitLengthY() { return m_kernelUnitLengthY.GetBaseVal(); }
	inline void SetKernelUnitLengthY(const wxSVGLength& n) { m_kernelUnitLengthY.GetBaseVal() = n; }

	inline bool GetPreserveAlpha() const { return m_preserveAlpha.GetBaseVal(); }
	inline void SetPreserveAlpha(const bool n) { m_preserveAlpha.GetBaseVal() = n; }

  public:
	inline long GetAnimatedOrderX() const { return m_orderX.GetAnimVal(); }
	inline void SetAnimatedOrderX(const long n) { m_orderX.GetAnimVal() = n; }

	inline long GetAnimatedOrderY() const { return m_orderY.GetAnimVal(); }
	inline void SetAnimatedOrderY(const long n) { m_orderY.GetAnimVal() = n; }

	inline wxSVGNumberList& GetAnimatedKernelMatrix() { return m_kernelMatrix.GetAnimVal(); }
	inline void SetAnimatedKernelMatrix(const wxSVGNumberList& n) { m_kernelMatrix.GetAnimVal() = n; }

	inline float GetAnimatedDivisor() const { return m_divisor.GetAnimVal(); }
	inline void SetAnimatedDivisor(const float n) { m_divisor.GetAnimVal() = n; }

	inline float GetAnimatedBias() const { return m_bias.GetAnimVal(); }
	inline void SetAnimatedBias(const float n) { m_bias.GetAnimVal() = n; }

	inline long GetAnimatedTargetX() const { return m_targetX.GetAnimVal(); }
	inline void SetAnimatedTargetX(const long n) { m_targetX.GetAnimVal() = n; }

	inline long GetAnimatedTargetY() const { return m_targetY.GetAnimVal(); }
	inline void SetAnimatedTargetY(const long n) { m_targetY.GetAnimVal() = n; }

	inline char GetAnimatedEdgeMode() const { return m_edgeMode.GetAnimVal(); }
	inline void SetAnimatedEdgeMode(const char n) { m_edgeMode.GetAnimVal() = n; }

	inline wxSVGLength& GetAnimatedKernelUnitLengthX() { return m_kernelUnitLengthX.GetAnimVal(); }
	inline void SetAnimatedKernelUnitLengthX(const wxSVGLength& n) { m_kernelUnitLengthX.GetAnimVal() = n; }

	inline wxSVGLength& GetAnimatedKernelUnitLengthY() { return m_kernelUnitLengthY.GetAnimVal(); }
	inline void SetAnimatedKernelUnitLengthY(const wxSVGLength& n) { m_kernelUnitLengthY.GetAnimVal() = n; }

	inline bool GetAnimatedPreserveAlpha() const { return m_preserveAlpha.GetAnimVal(); }
	inline void SetAnimatedPreserveAlpha(const bool n) { m_preserveAlpha.GetAnimVal() = n; }

  public:
	wxSVGFEConvolveMatrixElement(wxSVGDocument* doc, wxString tagName = wxT("feConvolveMatrix")):
	  wxSVGElement(doc, tagName) {}
	virtual ~wxSVGFEConvolveMatrixElement() {}
	bool SetAttribute(const wxString& name, const wxString& value);
	virtual const wxSVGDTD GetDtd() const { return wxSVG_FECONVOLVEMATRIX_ELEMENT; }
};

#endif // WX_SVG_FE_CONVOLVE_MATRIX_ELEMENT_H