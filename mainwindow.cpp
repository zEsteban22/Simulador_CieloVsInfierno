#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "consultarinfierno.h"
#include "consultarmundo.h"
#include "consultarcielo.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
		this->close();
		ConsultarInfierno ci;
		ci.setModal(true);
		ci.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
	this->close();
	ConsultarMundo cm;
	cm.setModal(1);
	cm.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
	this->close();
	ConsultarCielo cc;
	cc.setModal(1);
	cc.exec();
}
