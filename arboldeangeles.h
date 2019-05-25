#ifndef ARBOLDEANGELES_H
#define ARBOLDEANGELES_H

#include "nodoangel.h"
#include <QQueue>


struct ArbolDeAngeles
{
		NodoAngel*dios;
		int altura;
		void insertar(Persona*p,NodoAngel*s,std::string n);
		ArbolDeAngeles();
		QQueue<NodoAngel*>getUltimoNivel(){
			QQueue<NodoAngel*>q;
			return q;
		}
};

#endif // ARBOLDEANGELES_H
