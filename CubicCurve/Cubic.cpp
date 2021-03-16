#include "Cubic.h"



Cubic::Cubic() : Function(3)
{
	setV(1);
	setQ(1);
	setK(1);

	update();
}

std::vector<double> Cubic::valueAt(double x) const
{
	std::vector<double> ret;

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

void Cubic::setV(double v, ParamsMode mode /* = ParamsMode::Algebraic */)
{
	m_params[V] = v;
	update(mode);
}

void Cubic::setQ(double q, ParamsMode mode /* = ParamsMode::Algebraic */)
{
	m_params[Q] = q;
	update(mode);
}

void Cubic::setK(double k, ParamsMode mode /* = ParamsMode::Algebraic */)
{
	double newK = k;
	if (mode == ParamsMode::Geometry)
	{
		double pi = 3.14159265359;
		newK = tan(k*pi / 180);
	}
	m_params[K] = newK;
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

void Cubic::setAsymptote(double x, ParamsMode mode /* = ParamsMode::Geometry */)
{
	m_asymptotaX = x;
	update(mode);
}

double Cubic::asymptote(double v, double q)
{
	return v / (1 + 2 * v*q);
}

void Cubic::update(ParamsMode mode)
{
	switch (mode)
	{
	case ParamsMode::Algebraic:
		m_asymptotaX = asymptote(v(), q());
		break;
	case ParamsMode::Geometry:
		m_params[Q] = (v() - asymptote()) / (2 * v()*asymptote());
		break;
	default:
		break;
	}
	
}

double Cubic::f(double x) const
{
	double ret = (-k()*k()*(x+v())*x*x) / ((1+2*v()*q())*x-v());
	return ret;
}