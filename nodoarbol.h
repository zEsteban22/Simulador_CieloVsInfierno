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
		~NodoArbol(){
			if(hijoIzquierdo!=nullptr)
				hijoIzquierdo->~NodoArbol();
			if(hijoDerecho!=nullptr)
				hijoDerecho->~NodoArbol();
		}
		void corrimientoALaIzquierda();
};

#endif // NODOARBOL_H
