#include "Parabola.h"



Parabola::Parabola() : m_nParams{3}, Function(3)
{
}


Parabola::~Parabola()
{
}

double Parabola::valueAt(double x) const
{
	double a = m_params[0];
	double b = m_params[1];
	double c = m_params[2];
	
	double res = a*x*x + b*x + c;
	return res;
}

bool Parabola::resolveParams(const PointCoords & points)
{
	if(points.size() != m_nParams)
		return false;

	double x1 = points[0].first;
	double y1 = points[0].second;
	double x2 = points[1].first;
	double y2 = points[1].second;
	double x3 = points[2].first;
	double y3 = points[2].second;

	double delta = (x3-x1)*(x2-x1)*(x2-x3);

	m_params[0] = ((y2-y1)*(x3-x1)-(y3-y1)*(x2-x1)) / delta;
	m_params[1] = ((x2*x2-x1*x1)*(y3-y1)-(x3*x3-x1*x1)*(y2-y1)) / delta;
	m_params[2] = (x1*x1*(x2*y3-x3*y2)+x2*x2*(x3*y1-x1*y3)+x3*x3*(x1*y2-x2*y1)) / delta;
}
