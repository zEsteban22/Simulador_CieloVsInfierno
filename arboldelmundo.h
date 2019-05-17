#ifndef ARBOLDELMUNDO_H
#define ARBOLDELMUNDO_H
#include "listapersonas.h"
#include "nodoarbol.h"
#include <QQueue>
using namespace std;
struct ArbolDelMundo
{
		int altura;
		NodoArbol*raiz;
		ArbolDelMundo();
		bool insertar(NodoLista*nodo){
			return insertar(new NodoArbol(nodo));
		}
		bool insertar(NodoArbol*nodo){
			return insertar(nodo,raiz);
		}
		bool insertar(NodoArbol*nodo,NodoArbol*raiz){
			if (raiz==nullptr)
				return true;
			if (insertar(nodo,raiz->hijoIzquierdo)){
				raiz->hijoIzquierdo=nodo;
				return true;
			}
			insertar(nodo->hijoDerecho);
			return false;
		}
		void corrimientoALaIzquierda(NodoArbol*nodo){
			if(corrimientoALaIzquierda(nodo,raiz))
				raiz->valor=nodo->valor;
		}
		bool corrimientoALaIzquierda(NodoArbol*nodo,NodoArbol*raiz){
			if (nodo==nullptr)
				return false;
			else if (nodo==raiz){
				nodo->corrimientoALaIzquierda();
				return true;
			} else if (corrimientoALaIzquierda(nodo,raiz->hijoIzquierdo)){
				raiz->valor=nodo->valor;
				return true;
			} else {
				corrimientoALaIzquierda(nodo,raiz->hijoDerecho);
				return false;
			}
		}
		void aniadirNivel(NodoArbol*nodo){
			if (raiz==nullptr) raiz=nodo;
			else 
				insertar(nodo,raiz);
		}
		void aniadirNivel(NodoArbol*nodo,NodoArbol*raiz){
			if(nodo->valor<=raiz->valor)
				if(raiz->hijoIzquierdo==nullptr)
					raiz->hijoIzquierdo=nodo;
				else 
					insertar(nodo,raiz->hijoIzquierdo);
			else
				if (raiz->hijoDerecho==nullptr)
					raiz->hijoDerecho=nodo;
				else 
					insertar(nodo,raiz->hijoDerecho);
		}
		void completarArbol(ListaPersonas*lista){
			insertar(lista->primero());
			completarArbol(lista,0,lista->size());
		}
		void completarArbol(ListaPersonas*lista,int inicio, int fin){
			if (fin-inicio>100){
				insertar(lista->getByIndex(inicio));
				insertar(lista->getByIndex((inicio+fin)/2));
				completarArbol(lista,inicio,fin/2);
				completarArbol(lista,fin/2,fin);
			}
		}
		void vaciarArbol(){
			QQueue<NodoArbol*>restantes;
			NodoArbol*nodo=raiz;
			while (nodo!=nullptr&&nodo->hijoDerecho!=nullptr){
				nodo->nodoLista=nullptr;
				restantes.enqueue(nodo->hijoIzquierdo);
				restantes.enqueue(nodo->hijoDerecho);
				nodo=restantes.dequeue();
			}
		}
		Persona*getPersonaPorId(int);
		bool existe(int);
		bool existe(Persona*);
};

#endif // ARBOLDELMUNDO_H
