#include "ChartView.h"
#include <QScatterSeries>
#include <QValueAxis>

ChartView::ChartView(QWidget *parent)
	: QChartView(parent)
{
	QScatterSeries *series = new QScatterSeries;
	series->setMarkerSize(10);

	chart()->addSeries(series);
	chart()->legend()->hide();

	QValueAxis *axisX = new QValueAxis;
	axisX->setRange(-5, 5);
	axisX->setTickCount(11);
	axisX->setLabelFormat("%.2f");
	chart()->setAxisX(axisX, series);

	QValueAxis *axisY = new QValueAxis;
	axisY->setRange(-5, 5);
	axisY->setTickCount(11);
	axisY->setLabelFormat("%.2f");
	chart()->setAxisY(axisY, series);
}

ChartView::~ChartView()
{
}

void ChartView::onModeChanged(MouseMode mode)
{
	m_mode = mode;
}

void ChartView::mousePressEvent(QMouseEvent * event)
{
	switch (m_mode)
	{
	case NONE:
		break;
	case POINT:
		drawPoint(event->pos());
		break;
	case COUNT:
		break;
	default:
		break;
	}
	
	__super::mousePressEvent(event);
}

void ChartView::drawPoint(const QPoint & pos)
{
	auto chartPos = chart()->mapToValue(pos);
	auto* scatterSeries = static_cast<QScatterSeries*>(chart()->series()[0]);
	if (scatterSeries)
		scatterSeries->append(chartPos);
}
