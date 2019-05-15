#ifndef MUNDO_H
#define MUNDO_H
#include <QString>
#include <persona.h>
#include <iostream>
using namespace std;

struct Mundo
{
		QString*nombres[1000],*apellidos[1000];
		ArbolDelMundo arbol;
		Mundo();

};

#endif // MUNDO_H
