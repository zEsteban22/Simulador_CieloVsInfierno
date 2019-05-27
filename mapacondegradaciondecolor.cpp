#include "mapacondegradaciondecolor.h"
#include "ui_mapacondegradaciondecolor.h"
#define IMAGES_PATH "D:/My file/OneDrive/OneDrive - Estudiantes ITCR/Documentos/C++/Simulador_CieloVsInfierno/Imagenes/"
MapaConDegradacionDeColor::MapaConDegradacionDeColor(int africa,int america,int europa,int asia,int oceania,QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MapaConDegradacionDeColor)
{
	ui->setupUi(this);
	ui->label->setPixmap(QPixmap(tr(IMAGES_PATH)+"Africa"+QString::number(africa)+".png"));
	ui->label_2->setPixmap(QPixmap(tr(IMAGES_PATH)+"América"+QString::number(america)+".png"));
	ui->label_3->setPixmap(QPixmap(tr(IMAGES_PATH)+"Europa"+QString::number(europa)+".png"));
	ui->label_4->setPixmap(QPixmap(tr(IMAGES_PATH)+"Asia"+QString::number(asia)+".png"));
	ui->label_5->setPixmap(QPixmap(tr(IMAGES_PATH)+"Oceanía"+QString::number(oceania)+".png"));
}

MapaConDegradacionDeColor::~MapaConDegradacionDeColor()
{
	delete ui;
}
