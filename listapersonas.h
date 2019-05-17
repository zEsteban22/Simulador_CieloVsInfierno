#ifndef LISTAPERSONAS_H
#define LISTAPERSONAS_H

#include "nodolista.h"



struct ListaPersonas
{
		QVector<NodoLista>listaIndexada;
		NodoLista*primero(){
			return &listaIndexada.first();
		}
		ListaPersonas():listaIndexada(){
		}
		NodoLista*getByIndex(int i){
			return &listaIndexada[i];
		}
		int size(){
			return listaIndexada.size();
		}
		void insertar(Persona*p){
			listaIndexada.append(NodoLista(p,listaIndexada.empty()?nullptr:&listaIndexada.last()));
			listaIndexada.last().anterior->siguiente=&listaIndexada.last();
		}
};

#endif // LISTAPERSONAS_H
