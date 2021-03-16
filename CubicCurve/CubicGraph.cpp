#include "CubicGraph.h"
#include "Cubic.h"
#include <QSplineSeries>

CubicGraph::CubicGraph(QChart * chart) : Graph(chart, new QSplineSeries, new Cubic)
{
}

CubicGraph::~CubicGraph()
{
}

void CubicGraph::updateK(double k, ParamsMode mode)
{
	cubic()->setK(k, mode);
}

void CubicGraph::updateV(double v, ParamsMode mode)
{
	cubic()->setV(v, mode);
}

void CubicGraph::updateQ(double q, ParamsMode mode)
{
	if (mode == ParamsMode::Geometry)
		cubic()->setAsymptote(q);
	else
		cubic()->setQ(q);
}

void CubicGraph::draw()
{
	std::vector<double> X;
	auto domain = m_f->domain();
	//X.push_back(m_f->domain().first);
	for (double x = domain.first; x <= domain.second; x = x + 1e-2)
	{
		//if (m_f->checkDomain(x))
		X.push_back(x);
	}

	for (auto rIt = X.rbegin(); rIt < X.rend(); rIt++)
	{
		auto x = *rIt;
		auto y = m_f->valueAt(x);
		if (x >= 0)
		{
			m_series->append(x, y.at(0));
		}
		else
		{
			m_series->append(x, y.at(1));
		}
	}
	X.erase(X.begin());
	for (auto it = X.begin(); it < X.end(); it++)
	{
		auto x = *it;
		auto y = m_f->valueAt(x);
		if (x <= 0)
			m_series->append(x, y.at(0));
		else
			m_series->append(x, y.at(1));
	}
}

inline Cubic * CubicGraph::cubic()
{
	return dynamic_cast<Cubic*>(m_f);
}

inline const Cubic * CubicGraph::cubic() const
{
	return const_cast<const Cubic *>(dynamic_cast<Cubic*>(m_f));
}
