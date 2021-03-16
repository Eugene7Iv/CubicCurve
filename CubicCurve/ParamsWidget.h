#pragma once

#include <QWidget>
#include "ui_ParamsWidget.h"
#include "Shared.h"

class ParamsWidget : public QFrame
{
	Q_OBJECT

public:
	ParamsWidget(QWidget *parent = Q_NULLPTR);
	~ParamsWidget();

	ParamsMode paramMode() const;
	double k();
	double v();
	double q();

public slots:
	void onParamModeChange();
	void onDrawButton();

signals:
	void paramModeChanged(ParamsMode mode);
	void draw(double k, double v, double q, ParamsMode mode);

private:
	void updateLabels();
private:
	Ui::ParamsWidget m_ui;
	ParamsMode m_mode;
};
