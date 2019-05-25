#ifndef LISTAPERSONAS_H
#define LISTAPERSONAS_H

#include "nodolista.h"



struct ListaPersonas
{
		QVector<NodoLista>listaIndexada;
		NodoLista*primero();
		ListaPersonas();
		NodoLista*getByIndex(int i);
		int size();
		void insertar(Persona*p);
		void eliminar(NodoLista*n);
};

#endif // LISTAPERSONAS_H
