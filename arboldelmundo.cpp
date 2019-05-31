#include "arboldelmundo.h"

ArbolDelMundo::ArbolDelMundo()
{

}

void ArbolDelMundo::aniadirAlArbol(NodoLista*nodo){
	return aniadirAlArbol(new NodoArbol(nodo));
}

void ArbolDelMundo::aniadirAlArbol(NodoArbol*nodo){
	return aniadirAlArbol(nodo,raiz);
}

void ArbolDelMundo::aniadirAlArbol(NodoArbol*nodo, NodoArbol*raiz){
	NodoArbol**temp=&raiz;
	while(*temp!=nullptr)
		temp=&(nodo->nodoLista->persona->id<=(*temp)->nodoLista->persona->id?
						 (*temp)->hijoIzquierdo:
						 (*temp)->hijoDerecho
						 );
	*temp=nodo;
}

void ArbolDelMundo::corrimientoALaIzquierda(NodoArbol*nodo){
	if(corrimientoALaIzquierda(nodo,raiz))
		raiz->valor=nodo->valor;
}

bool ArbolDelMundo::corrimientoALaIzquierda(NodoArbol*nodo, NodoArbol*raiz){
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

void ArbolDelMundo::aniadirNivel(NodoArbol*nodo){
	if (raiz==nullptr) raiz=nodo;
	else
		aniadirAlArbol(nodo,raiz);
}

void ArbolDelMundo::aniadirNivel(NodoArbol*nodo, NodoArbol*raiz){
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

void ArbolDelMundo::completarArbol(ListaPersonas*lista){
	aniadirAlArbol(lista->getByIndex(lista->size()/2));
	completarArbol(lista,0,lista->size());
	NodoArbol*temp=raiz;
	cantNodos=1;
	while (temp!=nullptr){
		temp=temp->hijoIzquierdo;
		cantNodos*=2;
	}
	vaciarArbol();
}

void ArbolDelMundo::completarArbol(ListaPersonas*lista, int inicio, int fin){
	if (fin-inicio>100){
		aniadirAlArbol(lista->getByIndex(inicio));
		aniadirAlArbol(lista->getByIndex((inicio+fin)/2));
		completarArbol(lista,inicio,fin/2);
		completarArbol(lista,fin/2,fin);
	}
}

void ArbolDelMundo::vaciarArbol(){
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

NodoLista*ArbolDelMundo::getParaInsertar(int i){
	if (raiz==nullptr) return nullptr;
	NodoArbol*temp=raiz;
	while((*temp).hijoDerecho!=nullptr)
		temp=i<(*temp).valor?(*temp).hijoIzquierdo:(*temp).hijoDerecho;
	NodoLista*temp2=temp->nodoLista;
	while(temp2->persona->id<i)
		temp2=temp2->siguiente;
	return temp2;
}

Persona*ArbolDelMundo::getPersonaPorId(int i){
	NodoLista*n=getParaInsertar(i);
	return n&&n->persona->id==i?n->persona:nullptr;
}

bool ArbolDelMundo::existe(int i){
	NodoLista*n=getParaInsertar(i);
	return n!=nullptr&&n->persona->id==i;
}
