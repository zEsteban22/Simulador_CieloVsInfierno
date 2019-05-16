#ifndef MUNDO_H
#define MUNDO_H
#include "arboldelmundo.h"
#include "avl.h"
#include <QString>
#include <iostream>
#include <QMap>
using namespace std;

struct Mundo
{
		QMap<QString,QMap<QString,avl*>>familiasPorPais;
		ArbolDelMundo arbol;
		ListaPersonas listaPersonas;
		Mundo();
		void insertarNuevaPersona();
		void insertar10000Personas();
		void pecar();
};

#endif // MUNDO_H
