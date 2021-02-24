#pragma once
#include "Function.h"

class Linear :
	public Function
{
public:
	Linear();

	std::vector<double> valueAt(double x) const override;
	bool resolveParams(const PointCoords& points) override;
};

