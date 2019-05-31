#include "nodoarbol.h"

NodoArbol::NodoArbol(NodoLista*n):valor(n->persona->id),nodoLista(n),hijoIzquierdo(nullptr),hijoDerecho(nullptr){
}

void NodoArbol::corrimientoALaIzquierda(){
	nodoLista=nodoLista->anterior;
	valor=nodoLista->persona->id;
}
