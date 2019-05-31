#include "mainwindow.h"
#include <QApplication>
#include "mapacondegradaciondecolor.h"
#include "mundo.h"
#include <QDebug>
#include <QDir>
#include <consultarmundo.h>
int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	Mundo m;
	m.insertarPersonas(100);
	m.pecar();
	m.obrarBien();
	m.reportePaisesMasPecadores();
	return a.exec();
}
