#include "CubicCurve.h"
#include <QChartView>



CubicCurve::CubicCurve(QWidget *parent) : QMainWindow(parent), m_mode{NONE}
{
    m_ui.setupUi(this);

	connect(m_ui.actionClear, &QAction::triggered, m_ui.graphicsView, &ChartView::clear);
	connect(this, &CubicCurve::modeChanged, m_ui.graphicsView, &ChartView::onModeChanged);

	connect(m_ui.actionNone, &QAction::triggered, this, &CubicCurve::onNoneMode);
	connect(m_ui.actionPoint, &QAction::triggered, this, &CubicCurve::onPointMode);
	connect(m_ui.actionLinear, &QAction::triggered, this, &CubicCurve::onLinearMode);
	connect(m_ui.actionCubic, &QAction::triggered, this, &CubicCurve::onCubicMode);

	connect(m_ui.paramsWidget, &ParamsWidget::draw, m_ui.graphicsView, &ChartView::onDraw);

	m_ui.paramsWidget->hide();
	updateActions();
}

void CubicCurve::onNoneMode()
{
	m_mode = NONE;
	emit modeChanged(m_mode);
	updateActions();
	m_ui.paramsWidget->hide();
}

void CubicCurve::onPointMode()
{
	m_mode = POINT;
	emit modeChanged(m_mode);
	updateActions();
	m_ui.paramsWidget->hide();
}

void CubicCurve::onLinearMode()
{
	m_mode = LINEAR;
	emit modeChanged(m_mode);
	updateActions();
	m_ui.paramsWidget->hide();
}

void CubicCurve::onCubicMode()
{
	m_mode = CUBIC;
	emit modeChanged(m_mode);
	updateActions();
	m_ui.paramsWidget->show();
}

void CubicCurve::updateActions()
{
	m_ui.actionNone->setChecked(m_mode == NONE);
	m_ui.actionPoint->setChecked(m_mode == POINT);
	m_ui.actionLinear->setChecked(m_mode == LINEAR);
	m_ui.actionCubic->setChecked(m_mode == CUBIC);
}
