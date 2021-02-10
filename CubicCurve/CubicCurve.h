#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CubicCurve.h"

class CubicCurve : public QMainWindow
{
    Q_OBJECT

public:
    CubicCurve(QWidget *parent = Q_NULLPTR);

private:
    Ui::CubicCurveClass m_ui;
};
