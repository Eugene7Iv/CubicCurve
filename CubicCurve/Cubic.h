#pragma once
#include "Function.h"
#include <utility>

class Cubic : public Function
{
public:
	Cubic();

	std::vector<double> valueAt(double x) const override;
	bool resolveParams(const PointCoords& points) override;
	bool checkDomain(double x) const override;

	double v() const { return m_params[0]; }
	double q() const { return m_params[1]; }
	double k() const { return m_params[2]; }

	void setV(double v) { m_params[0] = v; }
	void setQ(double q) { m_params[1] = q; }
	void setK(double k) { m_params[2] = k; }

	std::pair<double, double> domain() const override;
	double asymptote() const;

	static double asymptote(double v, double q);

protected:
	void update();

private:
	double f(double x) const;

	double m_asymptotaX;
};

