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

QPushButton*MainWindow::getConsultarInfierno(){
	return ui->pushButton;
}

QPushButton*MainWindow::getConsultarCielo(){
	return ui->pushButton_2;
}

QPushButton *MainWindow::getConsultarMundo(){
    return ui->pushButton_3;
}

QPushButton *MainWindow::getGanador(){
    return ui->pushButton_4;
}






