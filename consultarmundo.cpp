#include "consultarmundo.h"
#include "ui_consultarmundo.h"
#include "mundo.cpp"

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
    insertarPersonas(ui->spinBox->value());

}


void ConsultarMundo::on_spinBox_valueChanged(int arg1)
{

}
