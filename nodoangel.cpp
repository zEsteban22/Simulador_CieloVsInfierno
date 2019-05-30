#include "nodoangel.h"

NodoAngel* NodoAngel::insertar(Persona*p, std::string nombre){
	NodoAngel*n=new NodoAngel(nombre,p);
	(hijo1==nullptr?hijo1:hijo2==nullptr?hijo2:hijo3)=n;
	return n;
}

NodoAngel::NodoAngel(std::string n,Persona*p):persona(p),nombre(n)
{
	hijo1=hijo2=hijo3=nullptr;
}
