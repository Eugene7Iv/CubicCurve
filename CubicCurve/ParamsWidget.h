#pragma once

#include <QWidget>
#include "ui_ParamsWidget.h"

class ParamsWidget : public QWidget
{
	Q_OBJECT

public:
	ParamsWidget(QWidget *parent = Q_NULLPTR);
	~ParamsWidget();

signals:
	void qChanged(double value);
	void vChanged(double value);
	void kChanged(double value);

private:
	Ui::ParamsWidget m_ui;
};
