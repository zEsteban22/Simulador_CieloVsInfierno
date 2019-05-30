#include "consultarcielo.h"
#include "ui_consultarcielo.h"

ConsultarCielo::ConsultarCielo(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);

}

ConsultarCielo::~ConsultarCielo()
{
	delete ui;
}

void ConsultarCielo::on_pushButton_clicked()
{
//	insertarPersonas(ui->spinBox->value());
}

