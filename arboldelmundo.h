#ifndef ARBOLDELMUNDO_H
#define ARBOLDELMUNDO_H
#include "listapersonas.h"
#include "nodoarbol.h"
#include <QQueue>
using namespace std;
struct ArbolDelMundo
{
		int cantNodos=1;
		NodoArbol*raiz;
		ArbolDelMundo();
		void aniadirAlArbol(NodoLista*nodo){
			return aniadirAlArbol(new NodoArbol(nodo));
		}
		void  aniadirAlArbol(NodoArbol*nodo){
			return aniadirAlArbol(nodo,raiz);
		}
		void aniadirAlArbol(NodoArbol*nodo,NodoArbol*raiz){
			NodoArbol**temp=&raiz;
			while(*temp!=nullptr)
				temp=&(nodo->nodoLista->persona->id<=(*temp)->nodoLista->persona->id?
								 (*temp)->hijoIzquierdo:
								 (*temp)->hijoDerecho
							);
			*temp=nodo;
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
				aniadirAlArbol(nodo,raiz);
		}
		void aniadirNivel(NodoArbol*nodo,NodoArbol*raiz){
			if(nodo->valor<=raiz->valor)
				if(raiz->hijoIzquierdo==nullptr)
					raiz->hijoIzquierdo=nodo;
				else 
					aniadirAlArbol(nodo,raiz->hijoIzquierdo);
			else
				if (raiz->hijoDerecho==nullptr)
					raiz->hijoDerecho=nodo;
				else 
					aniadirAlArbol(nodo,raiz->hijoDerecho);
		}
		void completarArbol(ListaPersonas*lista){
			aniadirAlArbol(lista->getByIndex(lista->size()/2));
			completarArbol(lista,0,lista->size());
			NodoArbol*temp=raiz;
			int altura=0;
			while (temp!=nullptr){
				temp=temp->hijoIzquierdo;
				altura++;
			}
			cantNodos=pow(2,altura);
		}
		void completarArbol(ListaPersonas*lista,int inicio, int fin){
			if (fin-inicio>100){
				aniadirAlArbol(lista->getByIndex(inicio));
				aniadirAlArbol(lista->getByIndex((inicio+fin)/2));
				completarArbol(lista,inicio,fin/2);
				completarArbol(lista,fin/2,fin);
			}
		}
		void vaciarArbol(){
			QQueue<NodoArbol*>restantes;
			NodoArbol*nodo=raiz;
			while (nodo!=nullptr&&nodo->hijoDerecho!=nullptr){
				nodo->valor=nodo->hijoDerecho->valor;
				nodo->nodoLista=nullptr;
				restantes.enqueue(nodo->hijoIzquierdo);
				restantes.enqueue(nodo->hijoDerecho);
				nodo=restantes.dequeue();
			}
		}
		Persona*getPersonaPorId(int){

		}
		bool existe(int);
		bool existe(Persona*);
};

#endif // ARBOLDELMUNDO_H
