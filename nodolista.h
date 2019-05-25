#ifndef NODOPERSONA_H
#define NODOPERSONA_H
#include "persona.h"

struct NodoLista
{
		Persona*persona;
		NodoLista*siguiente,*anterior;
		NodoLista():persona(nullptr),siguiente(nullptr),anterior(nullptr){
		}
		NodoLista(Persona*p):persona(p),siguiente(nullptr),anterior(nullptr){}
		NodoLista(Persona*p,NodoLista*a):persona(p),siguiente(nullptr),anterior(a){}
		bool operator==(NodoLista const&other){
			return persona->id==other.persona->id;
		}
};

#endif // NODOPERSONA_H
