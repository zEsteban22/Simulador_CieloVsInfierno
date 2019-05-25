#ifndef NODOANGEL_H
#define NODOANGEL_H
#include "persona.h"

struct NodoAngel
{
		NodoAngel*hijo1,*hijo2,*hijo3;
		Persona*persona;
		std::string nombre;
		void insertar(Persona*p,std::string nombre);
		NodoAngel(std::string n="",Persona*p=nullptr);
};

#endif // NODOANGEL_H
