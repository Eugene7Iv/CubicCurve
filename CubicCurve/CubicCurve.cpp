#include "CubicCurve.h"
#include <QChartView>



CubicCurve::CubicCurve(QWidget *parent) : QMainWindow(parent), m_mode{NONE}
{
    m_ui.setupUi(this);

	connect(m_ui.actionClear, &QAction::triggered, m_ui.graphicsView, &ChartView::clear);
	connect(m_ui.actionResetZoom, &QAction::triggered, m_ui.graphicsView, &ChartView::resetZoom);

	connect(m_ui.actionNone, &QAction::triggered, this, &CubicCurve::onNoneMode);
	connect(m_ui.actionCubic, &QAction::triggered, this, &CubicCurve::onCubicMode);

	connect(m_ui.paramsWidget, &ParamsWidget::draw, m_ui.graphicsView, &ChartView::onDraw);

	m_ui.paramsWidget->hide();

	m_ui.mainToolBar->insertSeparator(m_ui.actionClear);

	updateActions();
}

void CubicCurve::onNoneMode()
{
	m_mode = NONE;
	updateActions();
	m_ui.paramsWidget->hide();
}

void CubicCurve::onCubicMode()
{
	m_mode = CUBIC;
	updateActions();
	m_ui.paramsWidget->show();
}

void CubicCurve::updateActions()
{
	m_ui.actionNone->setChecked(m_mode == NONE);
	m_ui.actionCubic->setChecked(m_mode == CUBIC);
}
