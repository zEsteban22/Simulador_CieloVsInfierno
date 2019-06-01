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
QPushButton*ConsultarMundo::getInsertaPersona(){
    return ui->pushButton;
}
QPushButton*ConsultarMundo::getVolver(){
    return ui->pushButton_2;
}
QPushButton*ConsultarMundo::getPecarObrar(){
    return ui->pushButton_3;
}
QPushButton*ConsultarMundo::getEstadoPecados(){
    return ui->pushButton_4;
}
QPushButton*ConsultarMundo::getPaisesPecadores(){
    return ui->pushButton_5;
}
QPushButton*ConsultarMundo::getPaisesMenosPecadores(){
    return ui->pushButton_6;
}
QPushButton*ConsultarMundo::getMapaDegradacionPecados(){
    return ui->pushButton_7;
}
QPushButton*ConsultarMundo::getPaisesVirtuosos(){
    return ui->pushButton_8;
}
QPushButton*ConsultarMundo::getMenosVirtuosos(){
    return ui->pushButton_9;
}
QPushButton*ConsultarMundo::getMapaDecradacionVirtudes(){
    return ui->pushButton_10;
}
QSpinBox*ConsultarMundo::getSpinboxInsertarPersona(){
    return ui->spinBox;
}
QSpinBox*ConsultarMundo::getSpinboxInsertarID(){
    return ui->spinBox_2;
}
