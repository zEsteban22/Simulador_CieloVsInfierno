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

QPushButton*MainWindow::getBoton(){
	return ui->pushButton;
}

QPushButton*MainWindow::getBoton2(){
	return ui->pushButton_2;
}

QPushButton*MainWindow::getBoton3(){
	return ui->pushButton_3;
}


