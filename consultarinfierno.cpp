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

