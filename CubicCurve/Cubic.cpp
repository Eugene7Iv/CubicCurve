#include "Cubic.h"



Cubic::Cubic() : Function<std::pair<double, double>>(3)
{
	setV(1);
	setQ(1);
	setK(1);

	update();
}

std::pair<double, double> Cubic::valueAt(double x) const
{
	std::pair<double, double> ret;

	if (!checkDomain(x))
		return ret;

	double firstValue = sqrt(f(x));
	double secondValue = -sqrt(f(x));

	ret = { firstValue , secondValue };

	return ret;
}

bool Cubic::resolveParams(const PointCoords & points)
{
	setV(4);
	setQ(0.5);
	setK(3);

	update();

	return false;
}

bool Cubic::checkDomain(double x) const
{
	auto domainSegment = domain();
	return (x >= domainSegment.first) && (x <= domainSegment.second);
}

std::pair<double, double> Cubic::domain() const
{
	double first = v() > 0? -v(): asymptote();
	double second = v() < 0 ? -v() : asymptote();

	return std::pair<double, double>{first, second};
}


double Cubic::asymptote() const
{
	return m_asymptotaX;
}

double Cubic::asymptote(double v, double q)
{
	return v / (1 + 2 * v*q);
}

void Cubic::update()
{
	m_asymptotaX = asymptote(v(), q());
}

double Cubic::f(double x) const
{
	double ret = (-k()*k()*(x+v())*x*x) / ((1+2*v()*q())*x-v());
	return ret;
}