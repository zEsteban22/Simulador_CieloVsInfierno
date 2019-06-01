#include "consultarinfierno.h"
#include "ui_consultarinfierno.h"

ConsultarInfierno::ConsultarInfierno(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ConsultarInfierno)
{
	ui->setupUi(this);

}

ConsultarInfierno::~ConsultarInfierno()
{
	delete ui;
}

QPushButton*ConsultarInfierno::getVolver(){
	return ui->pushButton;
}

QPushButton*ConsultarInfierno::getCondenar(){
	return ui->pushButton_2;
}


