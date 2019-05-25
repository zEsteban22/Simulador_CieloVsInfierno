#include "nodoangel.h"

void NodoAngel::insertar(Persona*p, std::string nombre){
	(hijo1==nullptr?hijo1:hijo2==nullptr?hijo2:hijo3)=new NodoAngel(nombre,p);
}

NodoAngel::NodoAngel(std::string n,Persona*p):persona(p),nombre(n)
{
	hijo1=hijo2=hijo3=nullptr;
}
