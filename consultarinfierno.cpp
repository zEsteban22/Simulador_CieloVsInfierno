#include "consultarinfierno.h"
#include "ui_ConsultaInfierno.h"

ConsultarInfierno::ConsultarInfierno(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);

}

ConsultarInfierno::~ConsultarInfierno()
{
	delete ui;
}

void ConsultarInfierno::on_pushButton_clicked()
{
//	insertarPersonas(ui->spinBox->value());
}

