#pragma once
#include "Function.h"
class Parabola :
	public Function
{
public:
	Parabola();
	~Parabola();

	double valueAt(double x) const override;
	bool resolveParams(const PointCoords& points);

private:
	size_t m_nParams;
};

