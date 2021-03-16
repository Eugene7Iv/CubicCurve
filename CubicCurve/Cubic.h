#pragma once
#include "Function.h"
#include <utility>
#include "Shared.h"

class Cubic : public Function
{
	enum CubicParams
	{
		V,
		Q,
		K
	};
public:
	Cubic();

	std::vector<double> valueAt(double x) const override;
	bool resolveParams(const PointCoords& points) override;
	bool checkDomain(double x) const override;

	double v() const { return m_params[V]; }
	double q() const { return m_params[Q]; }
	double k() const { return m_params[K]; }

	void setV(double v, ParamsMode mode = ParamsMode::Algebraic);
	void setQ(double q, ParamsMode mode = ParamsMode::Algebraic);
	void setK(double k, ParamsMode mode = ParamsMode::Algebraic);

	std::pair<double, double> domain() const override;
	double asymptote() const;
	void setAsymptote(double x, ParamsMode mode = ParamsMode::Geometry);

	static double asymptote(double v, double q);

protected:
	void update(ParamsMode mode = ParamsMode::Algebraic);

private:
	double f(double x) const;

	double m_asymptotaX;
};

