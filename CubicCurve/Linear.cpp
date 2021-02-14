#include "Linear.h"



Linear::Linear() : Function(2)
{
}


Linear::~Linear()
{
}

double Linear::valueAt(double x) const
{
	double k = m_params[0];
	double b = m_params[1];

	double res = k * x + b;
	return res;
}

bool Linear::resolveParams(const PointCoords & points)
{
	double& k = m_params[0];
	double& b = m_params[1];

	double x1 = points[0].first;
	double y1 = points[0].second;
	double x2 = points[1].first;
	double y2 = points[1].second;

	k = (y1-y2) / (x1-x2);
	b = (y2*x1-y1*x2) / (x1 - x2);

	return true;
}
