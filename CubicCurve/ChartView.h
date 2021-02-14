#pragma once

#include <QChartView>
#include <QScatterSeries>
#include <QSplineSeries>

using namespace QtCharts;

enum MouseMode
{
	NONE,
	POINT,
	LINEAR,
	COUNT
};

class ChartView : public QChartView
{
	Q_OBJECT

public:
	ChartView(QWidget *parent);
	~ChartView();

	void onModeChanged(MouseMode mode);

protected:
	void mousePressEvent(QMouseEvent *event) override;

private:
	void drawPoint(const QPoint& pos);
	void drawLine(const QPoint& pos);

private:
	MouseMode m_mode;
	QScatterSeries* m_scatterSeries;
	QSplineSeries* m_splineSeries;
};
