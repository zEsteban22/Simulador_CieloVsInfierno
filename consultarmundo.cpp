#include "consultarmundo.h"
#include "ui_consultarmundo.h"

ConsultarMundo::ConsultarMundo(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);

}

ConsultarMundo::~ConsultarMundo()
{
	delete ui;
}

void ConsultarMundo::on_pushButton_clicked()
{
//	insertarPersonas(ui->spinBox->value());
}

