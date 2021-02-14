#include "CubicCurve.h"
#include <QChartView>



CubicCurve::CubicCurve(QWidget *parent) : QMainWindow(parent), m_mode{NONE}
{
    m_ui.setupUi(this);

	connect(m_ui.actionPoint, &QAction::triggered, this, &CubicCurve::onPointMode);
	connect(m_ui.actionNone, &QAction::triggered, this, &CubicCurve::onNoneMode);
	connect(m_ui.actionParabola, &QAction::triggered, this, &CubicCurve::onParabolaMode);
	connect(this, &CubicCurve::modeChanged, m_ui.graphicsView, &ChartView::onModeChanged);

	updateActions();
}

void CubicCurve::onPointMode()
{
	m_mode = POINT;
	emit modeChanged(m_mode);
	updateActions();
}

void CubicCurve::onParabolaMode()
{
	m_mode = PARABOLA;
	emit modeChanged(m_mode);
	updateActions();
}

void CubicCurve::onNoneMode()
{
	m_mode = NONE;
	emit modeChanged(m_mode);
	updateActions();
}

void CubicCurve::updateActions()
{
	m_ui.actionPoint->setChecked(m_mode == POINT);
	m_ui.actionNone->setChecked(m_mode == NONE);
	m_ui.actionParabola->setChecked(m_mode == PARABOLA);
}
