#include "ChartView.h"
#include <QScatterSeries>
#include <QLineSeries>
#include <QValueAxis>
#include "Linear.h"
#include "Cubic.h"
#include "CubicGraph.h"

ChartView::ChartView(QWidget *parent)
	: QChartView(parent)
{
	setRenderHint(QPainter::Antialiasing); // for more smooth spline
	chart()->legend()->hide();

	xMin = -5;
	xMax = 5;

	QValueAxis *axisX = new QValueAxis;
	axisX->setRange(xMin, xMax);
	axisX->setTickCount(11);
	axisX->setLabelFormat("%.2f");
	chart()->setAxisX(axisX);

	yMin = -5;
	yMax = 5;

	QValueAxis *axisY = new QValueAxis;
	axisY->setRange(-5, 5);
	axisY->setTickCount(11);
	axisY->setLabelFormat("%.2f");
	chart()->setAxisY(axisY);

	m_graph = new CubicGraph(chart());
}

ChartView::~ChartView()
{
	delete m_graph;
}

void ChartView::clear()
{
	for (auto series : chart()->series())
		static_cast<QXYSeries*>(series)->clear();
	resetZoom();
}

void ChartView::updateV(double v, ParamsMode mode)
{
	m_graph->updateV(v, mode);
}

void ChartView::updateQ(double q, ParamsMode mode)
{
	m_graph->updateQ(q, mode);
}

void ChartView::updateK(double k, ParamsMode mode)
{
	m_graph->updateK(k, mode);
}

void ChartView::onDraw(double k, double v, double q, ParamsMode mode)
{
	updateK(k, mode);
	updateV(v, mode);
	updateQ(q, mode);
	m_graph->update();
}

void ChartView::resetZoom()
{
	chart()->zoomReset();
}

void ChartView::wheelEvent(QWheelEvent * event)
{
	auto d = event->angleDelta().y();
	if (d > 0)
		chart()->zoomIn();
	else
		chart()->zoomOut();

	__super::wheelEvent(event);
}
