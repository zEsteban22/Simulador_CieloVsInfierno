#include "consultarcielo.h"
#include "ui_consultarcielo.h"

ConsultarCielo::ConsultarCielo(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ConsultarCielo)
{
	ui->setupUi(this);

}

ConsultarCielo::~ConsultarCielo()
{
	delete ui;
}

QPushButton*ConsultarCielo::getVolver(){
	return ui->pushButton_2;
}

QPushButton*ConsultarCielo::SalvarHumanos(){
	return ui->pushButton;
}




