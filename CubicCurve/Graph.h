#pragma once
#include <QtCharts/QXYSeries>
#include <QtCharts/QChart>
#include "Function.h"

using namespace QtCharts;

class Graph
{
public:
	Graph(QChart* chart, QXYSeries* series, Function* f);
	virtual ~Graph();
	virtual void draw() = 0;
	void update();

protected:
	QXYSeries* m_series;
	Function* m_f;
};

