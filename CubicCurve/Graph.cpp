#include "Graph.h"

Graph::Graph(QChart * chart, QXYSeries * series, Function* f) : m_series{series}, m_f{f}
{
	//it is important firstly add series to chart then attach axis to series
	chart->addSeries(m_series);
	m_series->attachAxis(chart->axisX());
	m_series->attachAxis(chart->axisY());
}

Graph::~Graph()
{
	delete m_f;
}

void Graph::update()
{
	m_series->clear();
	draw();
}
