#ifndef LISTAPERSONAS_H
#define LISTAPERSONAS_H

#include "nodolista.h"



struct ListaPersonas
{
		NodoLista*p;
		int s;
		NodoLista*primero();
		ListaPersonas();
		NodoLista*getByIndex(int i);
		int size();
		void insertar(Persona*p,NodoLista*);
		void eliminar(NodoLista*n);
};

#endif // LISTAPERSONAS_H
