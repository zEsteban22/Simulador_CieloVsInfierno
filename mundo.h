#ifndef MUNDO_H
#define MUNDO_H
#include "arboldelmundo.h"
#include "avl.h"
#include <QString>
#include <iostream>
#include <QMap>
using namespace std;

struct Mundo
{
		QMap<QString,QMap<QString,avl*>>familiasPorPais;
		string nombres[1000],apellidos[1000],profesiones[50],creencias[10];

		ArbolDelMundo arbol;
		ListaPersonas listaPersonas;
		Mundo();
		void insertarNuevaPersona(){

		}
		void insertar10000Personas();
		void pecar();
		void reportePaisesMasPecadores();
		void reportePaisesMenosPecadores();
		void reportePecadosPorFamilia(QString pais,QString apellido);
		void obrarBien();
		void reportePaisesMasBuenaGente();
		void reportePaisesMenosBuenaGente();
		void reporteVirtudesPorFamilia(QString pais,QString apellido);
};

#endif // MUNDO_H
