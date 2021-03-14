#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CubicCurve.h"

class CubicCurve : public QMainWindow
{
    Q_OBJECT

public:
    CubicCurve(QWidget *parent = Q_NULLPTR);

signals:
	void modeChanged(MouseMode mode);

private:
	void onNoneMode();
	void onPointMode();
	void onLinearMode();
	void onCubicMode();

	void updateActions();

private:
    Ui::CubicCurveClass m_ui;

	MouseMode m_mode;
};
