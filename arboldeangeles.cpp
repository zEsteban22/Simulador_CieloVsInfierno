#include "arboldeangeles.h"



void ArbolDeAngeles::insertar(Persona*p, NodoAngel*s, std::string n){
	s->insertar(p,n);
}

ArbolDeAngeles::ArbolDeAngeles(){
	altura=2;
	dios=new NodoAngel();
	dios->nombre="DIOS";
	dios->hijo1=new NodoAngel("Serafin");
	dios->hijo2=new NodoAngel("Querubin");
	dios->hijo3=new NodoAngel("Trono");
}
