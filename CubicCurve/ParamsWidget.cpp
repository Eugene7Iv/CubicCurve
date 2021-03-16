#include "ParamsWidget.h"
#include <QDoubleValidator>

ParamsWidget::ParamsWidget(QWidget *parent)
	: QFrame(parent), m_mode{ParamsMode::Geometry}
{
	m_ui.setupUi(this);
	QDoubleValidator* validator = new QDoubleValidator();
	m_ui.k_lineEdit->setValidator(validator);
	m_ui.q_lineEdit->setValidator(validator);
	m_ui.v_lineEdit->setValidator(validator);

	connect(m_ui.changeModeButton, &QPushButton::clicked, this, &ParamsWidget::onParamModeChange);
	connect(m_ui.drawButton, &QPushButton::clicked, this, &ParamsWidget::onDrawButton);

	m_ui.k_lineEdit->setText("45");
	m_ui.q_lineEdit->setText("1");
	m_ui.v_lineEdit->setText("1");

	updateLabels();
}

ParamsWidget::~ParamsWidget()
{
}

ParamsMode ParamsWidget::paramMode() const
{
	return m_mode;
}

double ParamsWidget::k()
{
	return m_ui.k_lineEdit->text().toDouble();
}

double ParamsWidget::v()
{
	return m_ui.v_lineEdit->text().toDouble();
}

double ParamsWidget::q()
{
	return m_ui.q_lineEdit->text().toDouble();
}

void ParamsWidget::onDrawButton()
{
	emit draw(k(), v(), q(), paramMode());
}

void ParamsWidget::updateLabels()
{
	QChar alpha{ 0xb1, 0x03 };
	switch (m_mode)
	{
	case ParamsMode::Algebraic:
		m_ui.k_label->setText("k");
		m_ui.q_label->setText("q");
		break;
	case ParamsMode::Geometry:
		m_ui.k_label->setText(alpha);
		m_ui.q_label->setText("x");
		break;
	default:
		break;
	}
}

void ParamsWidget::onParamModeChange()
{
	switch (m_mode)
	{
	case ParamsMode::Algebraic:
		m_mode = ParamsMode::Geometry;
		break;
	case ParamsMode::Geometry:
		m_mode = ParamsMode::Algebraic;
		break;
	default:
		break;
	}
	updateLabels();
}
