#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include<ctime>
#include<QVector>
#define str std::string
struct Persona
{
		int id;
		str nombre,apellido,pais,creencia,profesion,email;
		time_t momentoNacimiento;
		int pecados[7],virtudes[7];
		QVector<Persona*> hijos;
		Persona(str n,str a,str p,str c,str pf,str e,QVector<Persona*>h):nombre(n),apellido(a),pais(p),
			creencia(c),profesion(pf),email(e),momentoNacimiento(time(nullptr)),pecados{0,0,0,0,0,0,0},
			virtudes{0,0,0,0,0,0,0},hijos(h){
		}
};

#endif // PERSONA_H
