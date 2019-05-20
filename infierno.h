#ifndef INFIERNO_H
#define INFIERNO_H
#include "avl.h"
#include "mundo.h"
#include <QVector>

struct Infierno
{
		QVector<QMap<QString,QMap<QString,avl*>>> familiasPorPecado[7];
		std::string nombresDemonios[7];
		void condenar(Mundo mundo){

		}
		void logCondenacion(QString);
		Infierno():nombresDemonios{"Lucifer","Belcebú","Satán","Abadón","Mammón","Belfegor","Asmodeo"}{}
};

#endif // INFIERNO_H
