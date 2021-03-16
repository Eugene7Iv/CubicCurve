#pragma once

#include <QChartView>
#include <QScatterSeries>
#include <QSplineSeries>
#include "CubicGraph.h"

using namespace QtCharts;

enum MouseMode
{
	NONE,
	CUBIC,
};

class ChartView : public QChartView
{
	Q_OBJECT

public:
	ChartView(QWidget *parent);
	~ChartView();

	void clear();

	void updateV(double v, ParamsMode mode);
	void updateQ(double q, ParamsMode mode);
	void updateK(double k, ParamsMode mode);
	void onDraw(double k, double v, double q, ParamsMode mode);

	void resetZoom();
	
protected:
	void wheelEvent(QWheelEvent *event) override;

private:
	CubicGraph* m_graph;

	double xMin, xMax, yMin, yMax;
};
