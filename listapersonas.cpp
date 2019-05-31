#include "listapersonas.h"

NodoLista*ListaPersonas::primero(){
	return &listaIndexada.first();
}

ListaPersonas::ListaPersonas():listaIndexada(){
}

NodoLista*ListaPersonas::getByIndex(int i){
	return &listaIndexada[i];
}

int ListaPersonas::size(){
	return listaIndexada.size();
}

void ListaPersonas::insertar(Persona*p){
	listaIndexada.append(NodoLista(p,listaIndexada.empty()?nullptr:&listaIndexada.last()));
	if(listaIndexada.last().anterior!=nullptr)
		listaIndexada.last().anterior->siguiente=&listaIndexada.last();
}

void ListaPersonas::eliminar(NodoLista*n){
	n->anterior->siguiente=n->siguiente;
	n->siguiente->anterior=n->anterior;
	listaIndexada.removeOne(*n);
}
