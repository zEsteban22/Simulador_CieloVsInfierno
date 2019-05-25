#include "paraiso.h"

void Paraiso::aniadirAlCielo(Persona*p, NodoAngel*salvador, string n){
	cieloHash.insertar(p->id,p,salvador);
	arbolDeAngeles.insertar(p,salvador,n);
}

void Paraiso::salvarHumanos(Infierno*infierno){
	int cantSalvaciones=static_cast<int>(pow(3,arbolDeAngeles.altura));
	string generacion="G"+to_string(arbolDeAngeles.altura);
	QVector<string>nombresAniadidosEstaGeneracion;
	QQueue<NodoAngel*>ultimoNivelDeAngeles=arbolDeAngeles.getUltimoNivel();
	NodoAngel*salvadorActual=ultimoNivelDeAngeles.head();
	string nombre;
	Persona*persona;
	arbolDeAngeles.altura++;
	QQueue<Persona*>*menosPecadores=infierno->getMenosPecadores();
	for (int i=0;i<cantSalvaciones;i++){
		nombre=nombresDeAngeles[getRandomInt(0,10)];
		persona=menosPecadores->dequeue();
		nombresAniadidosEstaGeneracion.append(nombre);
		if (i%3==0)
			salvadorActual=ultimoNivelDeAngeles.dequeue();
		arbolDeAngeles.insertar(persona,salvadorActual,
														nombre+" ("+to_string(nombresAniadidosEstaGeneracion.count(nombre))+
														") "+generacion);
	}
}

Paraiso::Paraiso()
{

}
