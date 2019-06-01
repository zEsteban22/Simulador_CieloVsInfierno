#include "mainwindow.h"
#include <QApplication>
#include "controller.h"
#include "mapacondegradaciondecolor.h"
#include "mundo.h"
#include <QDebug>
#include <QDir>
#include <consultarmundo.h>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);/*
	Mundo m;
	m.insertarPersonas(1000);
	m.pecar();
	m.obrarBien();
	m.reportePaisesMasPecadores();
	m.reportePecadosPorFamilia();*/
	Controller controller;
	controller.start();
	return a.exec();
}
