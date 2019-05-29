#include "mainwindow.h"
#include <QApplication>
#include "mapacondegradaciondecolor.h"
#include "paraiso.h"
#include <QDebug>
#include <QDir>
int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	MapaConDegradacionDeColor w(2,0,1,4,3);
	w.show();
	return a.exec();
}
