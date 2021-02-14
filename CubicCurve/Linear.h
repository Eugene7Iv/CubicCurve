#pragma once
#include "Function.h"
class Linear :
	public Function
{
public:
	Linear();
	~Linear();

	virtual double valueAt(double x) const;
	virtual bool resolveParams(const PointCoords& points);
};

