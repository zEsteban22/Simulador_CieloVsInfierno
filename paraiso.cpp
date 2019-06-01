#include "cielo.h"

void Cielo::aniadirAlCielo(Persona*p, NodoAngel*salvador, string n){
	cieloHash.insertar(p->id,p,salvador);
	arbolDeAngeles.insertar(p,salvador,n);
}

string Cielo::salvarHumanos(Infierno infierno){
	string log="";
	int cantSalvaciones=static_cast<int>(pow(3,arbolDeAngeles.altura));
	string generacion="G"+to_string(arbolDeAngeles.altura);
	QVector<string>nombresAniadidosEstaGeneracion;
	QQueue<NodoAngel*>ultimoNivelDeAngeles=arbolDeAngeles.getUltimoNivel();
	NodoAngel*salvadorActual=ultimoNivelDeAngeles.head();
	string nombre;
	Persona*persona;
	arbolDeAngeles.altura++;
	QQueue<Persona*>*menosPecadores=infierno.getMenosPecadores();
	for (int i=0;i<cantSalvaciones;i++){
		nombre=nombresDeAngeles[getRandomInt(0,10)];
		persona=menosPecadores->dequeue();
		nombresAniadidosEstaGeneracion.append(nombre);
		if (i%3==0)
			salvadorActual=ultimoNivelDeAngeles.dequeue();
		log+="Humano #"+to_string(persona->id)+" "+persona->nombre+" "+persona->apellido+" salvado por "
				 +salvadorActual->nombre+" por "+to_string(persona->pecados[7])+" pecados vs "+
				to_string(persona->virtudes[7])+" buenas acciones.\n";
		cieloHash.insertar(persona->id,persona,arbolDeAngeles.insertar(
												 persona,salvadorActual,
												 nombre+" ("+to_string(nombresAniadidosEstaGeneracion.count(nombre))+
												 ") "+generacion));
	}
	return log;
}

int**Cielo::sumaAcciones(){
	static int acciones[2][7]={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
	QQueue<NodoAngel*>restantes;
	NodoAngel*angel=arbolDeAngeles.dios;
	while(angel!=nullptr){
		restantes.enqueue(angel->hijo1);
		restantes.enqueue(angel->hijo2);
		restantes.enqueue(angel->hijo3);
		if (angel->persona!=nullptr){
			for(int j=0;j<7;j++){
				acciones[0][j]+=angel->persona->pecados[j];
				acciones[1][j]+=angel->persona->virtudes[j];
			}
		}
		angel=restantes.dequeue();
	}
	return (int**)acciones;
}

Cielo::Cielo()
{

}
