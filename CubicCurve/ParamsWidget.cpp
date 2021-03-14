#include "ParamsWidget.h"
#include <QDoubleValidator>

ParamsWidget::ParamsWidget(QWidget *parent)
	: QWidget(parent)
{
	m_ui.setupUi(this);
	QDoubleValidator* validator = new QDoubleValidator();
	m_ui.k_lineEdit->setValidator(validator);
	m_ui.q_lineEdit->setValidator(validator);
	m_ui.v_lineEdit->setValidator(validator);

	connect(m_ui.k_lineEdit, &QLineEdit::editingFinished,[&](){
		emit kChanged(m_ui.k_lineEdit->text().toDouble());
	});	
	connect(m_ui.q_lineEdit, &QLineEdit::editingFinished, [&]() {
		emit qChanged(m_ui.q_lineEdit->text().toDouble());
	});
	connect(m_ui.v_lineEdit, &QLineEdit::editingFinished, [&]() {
		emit vChanged(m_ui.v_lineEdit->text().toDouble());
	});

	m_ui.k_lineEdit->setText("1");
	m_ui.q_lineEdit->setText("1");
	m_ui.v_lineEdit->setText("1");
}

ParamsWidget::~ParamsWidget()
{
}
