#include "listapersonas.h"

NodoLista*ListaPersonas::primero(){
	return p;
}

ListaPersonas::ListaPersonas():p(nullptr),s(0){
}

NodoLista*ListaPersonas::getByIndex(int i){
	NodoLista*temp=p;
	while(i-->0&&temp!=nullptr)
		temp=temp->siguiente;
	return temp;
}

int ListaPersonas::size(){
	return s;
}

void ListaPersonas::insertar(Persona*p,NodoLista*anterior){
	NodoLista*nuevo=new NodoLista(p,anterior);
	s++;
	if(this->p==nullptr)
		this->p=nuevo;
	else if(anterior==nullptr){
		this->p->anterior=nuevo;
		this->p->anterior->siguiente=this->p;
		this->p=this->p->anterior;
	}
	else {
		if (anterior->siguiente!=nullptr)
			anterior->siguiente->anterior=nuevo;
		nuevo->siguiente=anterior->siguiente;
		anterior->siguiente=nuevo;
	}
}

void ListaPersonas::eliminar(NodoLista*n){
	n->anterior->siguiente=n->siguiente;
	n->siguiente->anterior=n->anterior;
}
