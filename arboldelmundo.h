#ifndef ARBOLDELMUNDO_H
#define ARBOLDELMUNDO_H
#include "nodoarbol.h"
#include "listapersonas.h"
#include <QQueue>
#include <QStack>
using namespace std;
struct ArbolDelMundo
{
		int cantNodos=0;
		NodoArbol*raiz;
		ArbolDelMundo();
		void limpiarArbol(){
			if(raiz!=nullptr)
				raiz->~NodoArbol();
			raiz=nullptr;
		}
		void actualizarMenor(){
			if (raiz==nullptr)
				return;
			QStack<NodoArbol*>nodos;
			nodos.push(raiz);
			while(nodos.top()!=nullptr)
				nodos.push(nodos.top()->hijoIzquierdo);
			nodos.pop();
			while(nodos.top()->nodoLista->anterior!=nullptr)
				nodos.top()->nodoLista=nodos.top()->nodoLista->anterior;
			int valor=nodos.top()->valor;
			while(!nodos.empty())
				nodos.pop()->valor=valor;
		}
		void aniadirAlArbol(NodoLista*nodo);
		void  aniadirAlArbol(NodoArbol*nodo);
		void aniadirAlArbol(NodoArbol*nodo,NodoArbol*raiz);
		void corrimientoALaIzquierda(NodoArbol*nodo);
		bool corrimientoALaIzquierda(NodoArbol*nodo,NodoArbol*raiz);
		void aniadirNivel(NodoArbol*nodo);
		void aniadirNivel(NodoArbol*nodo,NodoArbol*raiz);
		void completarArbol(ListaPersonas*lista);
		void completarArbol(ListaPersonas*lista,int inicio, int fin,NodoArbol*);
		void vaciarArbol();
		NodoLista*getParaInsertar(int i);
		Persona*getPersonaPorId(int i);
		bool existe(int i);
};

#endif // ARBOLDELMUNDO_H
#include "listapersonas.h"
