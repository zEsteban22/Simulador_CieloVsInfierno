#include "persona.h"

void sumaDeArrays(QVector<int>*arr1,QVector<int>*arr2){
	if (arr1->empty())
		arr1->fill(0,8);
	for (int i=0;i<8;i++)
		arr1[0][i]+=arr2[0][i];
}

Persona::Persona(std::string n, std::string a, std::string p, std::string c, std::string pf, std::string e, int i):id(i),nombre(n),apellido(a),pais(p),creencia(c),profesion(pf),email(e),
	momentoNacimiento(time(nullptr)),pecados{0,0,0,0,0,0,0},virtudes{0,0,0,0,0,0,0},hijos(){
}
void Persona::modificarAcciones(bool pecados){
	int*acciones=pecados?this->pecados:virtudes;

	int cantPecados;
	for (int i=0;i<7;i++){
		cantPecados=getRandomInt(0,100);
		acciones=pecados?this->pecados:virtudes;
		acciones[i]+=cantPecados;
		acciones[7]+=cantPecados;
		for (Persona*hijo : hijos){
			acciones=pecados?hijo->pecados:hijo->virtudes;
			acciones[i]+=cantPecados/2;
			acciones[7]+=cantPecados/2;
			for (Persona* nieto : hijo->hijos){
				acciones=pecados?nieto->pecados:nieto->virtudes;
				acciones[i]+=cantPecados/4;
				acciones[7]+=cantPecados/4;
			}
		}
	}
	;
}
void Persona::pecar(){
	modificarAcciones(true);
}


void Persona::obrarBien(){
	modificarAcciones(false);
}

int Persona::sumaPecados(){
	int suma=0;
	for(int i:pecados)
		suma+=i;
	return suma;
}

int Persona::sumaVirtudes(){
	int suma=0;
	for(int i:virtudes)
		suma+=i;
	return suma;
}

std::string Persona::to_string(int cantTaps){
	std::string inicioDeLinea="";
	for(int i=0;i<cantTaps;i++)
		inicioDeLinea+="\t";
	std::string salida=inicioDeLinea+"ID: ";
	salida+=inicioDeLinea+std::to_string(id)+"\n\t";
	salida+=inicioDeLinea+"Nombre: "+nombre+"\n\t";
	salida+=inicioDeLinea+"Apellido: "+apellido+"\n\t";
	salida+=inicioDeLinea+"Pais: "+pais+"\n\t";
	salida+=inicioDeLinea+"Creencia: "+creencia+"\n\t";
	salida+=inicioDeLinea+"Profesión: "+profesion+"\n\t";
	salida+=inicioDeLinea+"Email: "+email+"\n\t";
	char buff[30];
	strftime(buff, 30, "El %d/%m/%Y a las: %H:%M", localtime(&momentoNacimiento));
	salida+=inicioDeLinea+"Fecha de nacimiento: ";
	salida+=buff;
	salida+="\n\t";
	std::string strHijos="HIJOS:\n\t";
	for (auto hijo:hijos)
		strHijos+=hijo->to_string(cantTaps+1);
	if (strHijos!="HIJOS:\n\t")
		salida+=inicioDeLinea+strHijos;
	return salida;
}
