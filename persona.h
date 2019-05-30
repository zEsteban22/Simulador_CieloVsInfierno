#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include<ctime>
#include<QVector>
#include"randomxd.h"

void sumaDeArrays(int arr1[8],int arr2[8]);
struct Persona
{
		int id;
		std::string nombre,apellido,pais,creencia,profesion,email;
		time_t momentoNacimiento;
		int pecados[8],virtudes[8];
		QVector<Persona*> hijos;
		Persona(std::string n,std::string a,std::string p,std::string c,std::string pf,std::string e,
						int i);
		void pecar();
		void obrarBien();
		void modificarAcciones(bool);
		int sumaPecados();
		int sumaVirtudes();
		std::string to_string(int cantTaps=0);
};

#endif // PERSONA_H
