#ifndef MUNDO_H
#define MUNDO_H
#include "arboldelmundo.h"
#include <QString>
#include <iostream>
using namespace std;

struct Mundo
{
		QString*nombres[1000],*apellidos[1000];
		ArbolDelMundo arbol;
		ListaPersonas listaPersonas;
		Mundo();
		void insertarNuevaPersona();
		void insertar10000Personas();

};

#endif // MUNDO_H
