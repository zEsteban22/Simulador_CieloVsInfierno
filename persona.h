#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include<ctime>
#include<QVector>
#include"random.cpp"
#define str std::string
struct Persona
{
		int id;
		str nombre,apellido,pais,creencia,profesion,email;
		time_t momentoNacimiento;
		int pecados[7],virtudes[7];
		QVector<Persona*> hijos;
		Persona(str n,str a,str p,str c,str pf,str e):nombre(n),apellido(a),pais(p),
			creencia(c),profesion(pf),email(e),momentoNacimiento(time(nullptr)),pecados{0,0,0,0,0,0,0},
			virtudes{0,0,0,0,0,0,0}{
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
};

#endif // PERSONA_H
