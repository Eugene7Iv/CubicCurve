#include "ChartView.h"
#include <QScatterSeries>
#include <QLineSeries>
#include <QValueAxis>
#include "Linear.h"
#include "Cubic.h"

ChartView::ChartView(QWidget *parent)
	: QChartView(parent)
{
	setRenderHint(QPainter::Antialiasing); // for more smooth spline

	m_scatterSeries = new QScatterSeries;
	m_scatterSeries->setMarkerSize(10);

	m_splineSeries = new QSplineSeries;

	//it is important firstly add series to chart then attach axis to series
	chart()->addSeries(m_scatterSeries);
	chart()->addSeries(m_splineSeries);
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

void ChartView::clear()
{
	for (auto series : chart()->series())
		static_cast<QXYSeries*>(series)->clear();
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
	case CUBIC:
		drawCubic();
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

		lineSeries->append(minX, f.valueAt(minX).at(0));
		lineSeries->append(maxX, f.valueAt(maxX).at(1));
		coords.resize(0);
	}
}

void ChartView::drawCubic()
{
	QSplineSeries* s = new QSplineSeries;
	chart()->addSeries(s);
	s->attachAxis(chart()->axisX());
	s->attachAxis(chart()->axisY());

	Cubic f;
	//asymptote
	QLineSeries* lineSeries = new QLineSeries;
	QPen pen = lineSeries->pen();
	pen.setWidth(1);
	pen.setStyle(Qt::DashLine);
	lineSeries->setPen(pen);
	chart()->addSeries(lineSeries);
	lineSeries->attachAxis(chart()->axisX());
	lineSeries->attachAxis(chart()->axisY());

	lineSeries->append(f.asymptote(), yMax);
	lineSeries->append(f.asymptote(), yMin);

	std::vector<double> X;
	X.push_back(f.domain().first);
	for (double x = xMin; x <= xMax; x = x + 1e-2)
	{	
		if (f.checkDomain(x))
			X.push_back(x);
	}

	for (auto rIt = X.rbegin(); rIt < X.rend(); rIt++)
	{
		auto x = *rIt;
		auto y = f.valueAt(x);
		if (x >= 0)
		{
			s->append(x, y.at(0));
		}
		else
		{
			s->append(x, y.at(1));
		}
	}
	X.erase(X.begin());
	for (auto it = X.begin(); it < X.end(); it++)
	{
		auto x = *it;
		auto y = f.valueAt(x);
		if (x <= 0)
			s->append(x, y.at(0));
		else
			s->append(x, y.at(1));
	}
}
