#include "nodoarbol.h"

NodoArbol::NodoArbol(NodoLista*n):valor(0),nodoLista(n),hijoIzquierdo(nullptr),hijoDerecho(nullptr){
}

void NodoArbol::corrimientoALaIzquierda(){
	nodoLista=nodoLista->anterior;
	valor=nodoLista->persona->id;
}
