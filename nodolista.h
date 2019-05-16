#ifndef NODOPERSONA_H
#define NODOPERSONA_H
#include "persona.h"

struct NodoLista
{
		Persona*persona;
		NodoLista*siguiente,*anterior;
		NodoLista();
};

#endif // NODOPERSONA_H
