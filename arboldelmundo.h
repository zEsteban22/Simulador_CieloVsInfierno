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
			if (nodo->valor==raiz->valor)
				return;
			else if(nodo->valor<raiz->valor)
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
			NodoArbol*ultimoInsertado;
			int ultimaPosicion;
			for(int i=0;i<=lista->lenght/10;i++){
				ultimoInsertado=new NodoArbol(lista->getByIndex(i*10));
				insertar(ultimoInsertado);
				ultimaPosicion=i*10;
			}
			
		}
		Persona*getPersonaPorId(int);
		bool existe(int);
		bool existe(Persona*);
};

#endif // ARBOLDELMUNDO_H
