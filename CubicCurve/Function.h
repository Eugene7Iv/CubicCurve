#pragma once
#include <vector>

using PointCoords = std::vector<std::pair<double, double>>;


class Function
{
public:
	Function(size_t nParams)
	{
		m_params.reserve(nParams);
		m_params.resize(nParams);
	}
	virtual ~Function(){}

	virtual std::vector<double> valueAt(double x) const = 0;
	virtual bool resolveParams(const PointCoords& points) = 0;
	virtual std::pair<double, double> domain() const;
	virtual bool checkDomain(double x) const
	{
		return false;
	}

protected:
	std::vector<double> m_params;

	bool m_isParamsResolved;
};

