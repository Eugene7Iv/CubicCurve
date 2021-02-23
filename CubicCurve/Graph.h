#pragma once
#include <QtCharts/QXYSeries>
#include <QtCharts/QChart>
#include "Function.h"

using namespace QtCharts;

class Graph
{
public:
	Graph(QChart* chart, QXYSeries* series);
	virtual ~Graph();
	virtual void generateSeries() = 0;

private:
	QXYSeries* m_series;
};

