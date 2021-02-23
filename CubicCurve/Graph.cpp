#include "Graph.h"

Graph::Graph(QChart * chart, QXYSeries * series) : m_series{series}
{
		chart->addSeries(m_series);
		m_series->attachAxis(chart->axisX());
		m_series->attachAxis(chart->axisY());
}

Graph::~Graph()
{
}
