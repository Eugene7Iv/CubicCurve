#pragma once
#include "Function.h"

class Linear :
	public Function<double>
{
public:
	Linear();

	double valueAt(double x) const override;
	bool resolveParams(const PointCoords& points) override;
};

