#include "ChartView.h"

ChartView::ChartView(QWidget *parent)
	: QChartView(parent)
{
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
	case COUNT:
		break;
	default:
		break;
	}
	
	__super::mousePressEvent(event);
}

void ChartView::drawPoint(const QPoint & pos)
{
	QGraphicsEllipseItem* item = new QGraphicsEllipseItem(QRectF(-3, -3, 6, 6));
	const QColor color(255, 0, 0, 255);
	item->setZValue(100);
	QPen pen(color);
	pen.setWidth(3);
	item->setBrush(color);
	item->setPen(pen);
	scene()->addItem(item);
	item->setPos(pos);
}
