#pragma once

#include <QChartView>
#include <QScatterSeries>
#include <QSplineSeries>
#include "CubicGraph.h"

using namespace QtCharts;

enum MouseMode
{
	NONE,
	POINT,
	LINEAR,
	CUBIC,
	COUNT
};

class ChartView : public QChartView
{
	Q_OBJECT

public:
	ChartView(QWidget *parent);
	~ChartView();

	void onModeChanged(MouseMode mode);
	void clear();

	void updateV(double v);
	void updateQ(double q);
	void updateK(double k);

protected:
	void mousePressEvent(QMouseEvent *event) override;

private:
	void drawPoint(const QPoint& pos);
	void drawLine(const QPoint& pos);
	void drawCubic();

private:
	MouseMode m_mode;
	QScatterSeries* m_scatterSeries;
	QSplineSeries* m_splineSeries;
	CubicGraph* m_graph;

	double xMin, xMax, yMin, yMax;
};
