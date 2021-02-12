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
}
