#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "nodolista.h"



struct NodoArbol
{
		int valor;
		NodoLista*nodoLista;
		NodoArbol*hijoIzquierdo,*hijoDerecho;
		NodoArbol();
		NodoArbol(NodoLista*n=nullptr);
		void corrimientoALaIzquierda();
};

#endif // NODOARBOL_H
