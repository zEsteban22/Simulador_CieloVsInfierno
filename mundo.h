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
		QMap<QString,QMap<QString,avl_tree*>>familiasPorPais;
		string nombres[1000],apellidos[1000],profesiones[50],creencias[10];

		ArbolDelMundo arbol;
		ListaPersonas listaPersonas;
		Mundo();
		void insertarNuevaPersona(){

		}
		void insertar10000Personas(){
			for(int i=0;i<10000;i++)
				insertarNuevaPersona();
		}
		void pecar(){
			for (NodoLista*temp=listaPersonas.primero();temp!=nullptr;temp=temp->siguiente)
				temp->persona->pecar();
		}
		void reporte(bool mayores,bool pecadores){
			QMap<QString,int>cantidadAccionesPorPais;
			for(auto i:familiasPorPais.keys()){
				for(auto j:familiasPorPais.value(i).keys()){
					cantidadAccionesPorPais[j]+=pecadores?
																				familiasPorPais.value(i).value(j)->sumaPecados():
																				familiasPorPais.value(i).value(j)->sumaVirtudes();
				}
			}
		}
		void reportePaisesMasPecadores();
		void reportePaisesMenosPecadores();
		void reportePecadosPorFamilia(QString pais,QString apellido);
		void obrarBien(){
			for (NodoLista*temp=listaPersonas.primero();temp!=nullptr;temp=temp->siguiente)
				temp->persona->obrarBien();
		}
		void reportePaisesMasBuenaGente();
		void reportePaisesMenosBuenaGente();
		void reporteVirtudesPorFamilia(QString pais,QString apellido);
};

#endif // MUNDO_H
