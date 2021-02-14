#pragma once
#include <vector>

using PointCoords = std::vector<std::pair<double, double>>;

class Function
{
public:
	Function(size_t nParams);
	virtual ~Function();

	virtual double valueAt(double x) const = 0;
	virtual bool resolveParams(const PointCoords& points) = 0;

protected:
	std::vector<double> m_params;

	bool m_isParamsResolved;
};

