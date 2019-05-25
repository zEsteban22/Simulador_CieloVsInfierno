#ifndef ARBOLDELMUNDO_H
#define ARBOLDELMUNDO_H
#include "listapersonas.h"
#include "nodoarbol.h"
#include <QQueue>
using namespace std;
struct ArbolDelMundo
{
		int cantNodos=0;
		NodoArbol*raiz;
		ArbolDelMundo();
		void aniadirAlArbol(NodoLista*nodo);
		void  aniadirAlArbol(NodoArbol*nodo);
		void aniadirAlArbol(NodoArbol*nodo,NodoArbol*raiz);
		void corrimientoALaIzquierda(NodoArbol*nodo);
		bool corrimientoALaIzquierda(NodoArbol*nodo,NodoArbol*raiz);
		void aniadirNivel(NodoArbol*nodo);
		void aniadirNivel(NodoArbol*nodo,NodoArbol*raiz);
		void completarArbol(ListaPersonas*lista);
		void completarArbol(ListaPersonas*lista,int inicio, int fin);
		void vaciarArbol();
		NodoLista*getParaInsertar(int i);
		Persona*getPersonaPorId(int i);
		bool existe(int i);
};

#endif // ARBOLDELMUNDO_H
