#pragma once

#include <QChartView>

using namespace QtCharts;

enum MouseMode
{
	NONE,
	POINT,
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

private:
	MouseMode m_mode;
};
