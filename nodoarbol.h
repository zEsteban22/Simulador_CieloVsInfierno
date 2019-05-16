#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "nodolista.h"



struct NodoArbol
{
		int valor;
		NodoLista*nodoLista;
		NodoArbol*hijoIzquierdo,*hijoDerecho;
		NodoArbol();
		NodoArbol(NodoLista*);
		void corrimientoALaIzquierda(){
			nodoLista=nodoLista->anterior;
			valor=nodoLista->persona->id;
		}
};

#endif // NODOARBOL_H
