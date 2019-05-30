#ifndef PARAISO_H
#define PARAISO_H

#include "arboldeangeles.h"
#include "cielohash.h"
#include "infierno.h"



struct Paraiso
{
		CieloHash cieloHash;
		ArbolDeAngeles arbolDeAngeles;
		string nombresDeAngeles[10]={"Miguel","Nuriel","Aniel","Rafael","Gabriel","Shamsiel","Raguel",
																 "Uriel","Azrael","Sariel"};
		void aniadirAlCielo(Persona*p,NodoAngel*salvador,string n);
		string salvarHumanos(Infierno infierno);
		Paraiso();
};

#endif // PARAISO_H
