#include "consultarmundo.h"
#include "ui_consultarmundo.h"
#include "mundo.cpp"

ConsultarMundo::ConsultarMundo(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ConsultarMundo)
{
	ui->setupUi(this);

}

ConsultarMundo::~ConsultarMundo()
{
	delete ui;
}
