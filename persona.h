#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include<ctime>
#include<QVector>
#include"random.cpp"
struct Persona
{
		int id;
		std::string nombre,apellido,pais,creencia,profesion,email;
		time_t momentoNacimiento;
		int pecados[8],virtudes[8];
		QVector<Persona*> hijos;
		Persona(std::string n,std::string a,std::string p,std::string c,std::string pf,std::string e):
			nombre(n),apellido(a),pais(p),creencia(c),profesion(pf),email(e),
			momentoNacimiento(time(nullptr)),pecados{0,0,0,0,0,0,0},virtudes{0,0,0,0,0,0,0}{
		}
		void pecar(){
			for (int i=0;i<7;i++)
				pecados[i]+=getRandomInt(0,100);
		}
		void obrarBien(){
			for(int i=0;i<7;i++)
				virtudes[i]+=getRandomInt(0,100);
		}
		int sumaPecados(){
			int suma=0;
			for(int i:pecados)
				suma+=i;
			return suma;
		}
		int sumaVirtudes(){
			int suma=0;
			for(int i:virtudes)
				suma+=i;
			return suma;
		}
};

#endif // PERSONA_H
