#pragma once
#include <vector>

using PointCoords = std::vector<std::pair<double, double>>;

template<typename T>
class Function
{
public:
	Function(size_t nParams)
	{
		m_params.reserve(nParams);
		m_params.resize(nParams);
	}
	virtual ~Function(){}

	virtual T valueAt(double x) const = 0;
	virtual bool resolveParams(const PointCoords& points) = 0;
	virtual bool checkDomain(double x) const
	{
		return false;
	}

protected:
	std::vector<double> m_params;

	bool m_isParamsResolved;
};

