#include "ChartView.h"
#include <QScatterSeries>
#include <QLineSeries>
#include <QValueAxis>
#include "Linear.h"

ChartView::ChartView(QWidget *parent)
	: QChartView(parent)
{
	m_scatterSeries = new QScatterSeries;
	m_scatterSeries->setMarkerSize(10);

	m_splineSeries = new QSplineSeries;

	//it is important firstly add series to chart then attach axis to series
	chart()->addSeries(m_scatterSeries);
	chart()->addSeries(m_splineSeries);
	chart()->legend()->hide();

	QValueAxis *axisX = new QValueAxis;
	axisX->setRange(-5, 5);
	axisX->setTickCount(11);
	axisX->setLabelFormat("%.2f");
	chart()->setAxisX(axisX);

	QValueAxis *axisY = new QValueAxis;
	axisY->setRange(-5, 5);
	axisY->setTickCount(11);
	axisY->setLabelFormat("%.2f");
	chart()->setAxisY(axisY);

	m_scatterSeries->attachAxis(axisX);
	m_scatterSeries->attachAxis(axisY);

	m_splineSeries->attachAxis(axisX);
	m_splineSeries->attachAxis(axisY);
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
	case LINEAR:
		drawLine(event->pos());
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
	if (m_scatterSeries)
		m_scatterSeries->append(chartPos);
}

void ChartView::drawLine(const QPoint & pos)
{
	static PointCoords coords;
	auto chartPos = chart()->mapToValue(pos);
	drawPoint(pos);
	coords.push_back({ chartPos.x(), chartPos.y() });
	if (coords.size() == 2)
	{
		Linear f;
		f.resolveParams(coords);
		double minX = static_cast<QValueAxis*>(chart()->axisX())->min();
		double maxX = static_cast<QValueAxis*>(chart()->axisX())->max();

		QLineSeries* lineSeries = new QLineSeries;
		chart()->addSeries(lineSeries);
		lineSeries->attachAxis(chart()->axisX());
		lineSeries->attachAxis(chart()->axisY());

		lineSeries->append(minX, f.valueAt(minX));
		lineSeries->append(maxX, f.valueAt(maxX));
		coords.resize(0);
	}
	
}
