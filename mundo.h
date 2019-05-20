#ifndef MUNDO_H
#define MUNDO_H
#include "arboldelmundo.h"
#include "avl.h"
#include <QString>
#include <iostream>
#include <QMap>

using namespace std;
struct comparador
{
		bool ascendente;
		comparador(bool a):ascendente(a){}
		bool operator()(QPair<int*,QString> const &a, QPair<int*,QString> const &b) const {
			return ascendente== a.first[8] < b.first[8];
		}
};
struct Mundo
{
		QMap<QString,QMap<QString,avl_tree*>>familiasPorPais;
		string nombres[1000],apellidos[1000],paises[100],profesiones[50],creencias[10];

		ArbolDelMundo arbol;
		ListaPersonas lista;
		Mundo();
		void insertarNuevaPersona(){
			Persona*nuevaPersona=new Persona(nombres[getRandomInt(0,1000)],apellidos[getRandomInt(0,1000)]
					,paises[getRandomInt(0,100)],creencias[getRandomInt(0,10)],profesiones[getRandomInt(0,50)]
					,"xllestebanllx@gmail.com");
			lista.insertar(nuevaPersona);
			if (arbol.cantNodos<lista.size()*0.01)
				arbol.completarArbol(&lista);
		}
		void insertar10000Personas(){
			for(int i=0;i<10000;i++)
				insertarNuevaPersona();
		}
		void pecar(){
			for (NodoLista*temp=lista.primero();temp!=nullptr;temp=temp->siguiente)
				temp->persona->pecar();
		}
		QMap<QString,int*>cantAccionesPorFamilia(bool pecados,QString pais){
			QMap<QString,int*>accionesPorFamilia;
			for(auto j:familiasPorPais.value(pais).keys())
					sumaDeArrays(accionesPorFamilia[j],(pecados?
																								 familiasPorPais.value(pais).value(j)->sumaPecados():
																								 familiasPorPais.value(pais).value(j)->sumaVirtudes())
											 );
			return accionesPorFamilia;
		}
		QMap<QString,int*>cantAccionesPorPais(bool pecados){
			QMap<QString,int*>accionesPorPais;
			for(auto i:familiasPorPais.keys())
				for (auto j:cantAccionesPorFamilia(pecados,i))
					sumaDeArrays(accionesPorPais[i],j);
			return accionesPorPais;
		}
		QVector<QPair<int*,QString>>ordenar(QMap<QString,int*>cantidadAccionesPorPais,bool ascendente){
			QVector<QPair<int*,QString>> mapVector;
			for (auto i :cantidadAccionesPorPais.keys())
				mapVector.append(QPair<int*,QString>(cantidadAccionesPorPais[i],i));
			sort(mapVector.begin(),mapVector.end(),comparador(ascendente));
			return mapVector;
		}
		void reporte(bool ascendente,bool pecadores,int cant){
			QVector<QPair<int*,QString>> resultado=ordenar(cantAccionesPorPais(pecadores),ascendente);
			imprimirResultado(resultado,cant);
		}
		void imprimirResultado(QVector<QPair<int*,QString>>resultado,int cant){
			QString salida="";
			for (int i = 0; i < cant&&i<resultado.size(); ++i)
				salida+=QString::number(i)+") "+resultado[i].second+" con "+QString::number(resultado[i].first[8])+"\n";
			cout<<salida.toStdString();
		}
		void reportePaisesMasPecadores(){
			reporte(false,true,10);
		}
		void reportePaisesMenosPecadores(){
			reporte(true,true,5);
		}
		void reportePecadosPorFamilia(QString pais,QString apellido){

		}

		void obrarBien(){
			for (NodoLista*temp=lista.primero();temp!=nullptr;temp=temp->siguiente)
				temp->persona->obrarBien();
		}
		void reportePaisesMasBuenaGente(){
			reporte(false,false,10);
		}
		void reportePaisesMenosBuenaGente(){
			reporte(true,false,5);
		}
		void reporteVirtudesPorFamilia(QString pais,QString apellido);
};

#endif // MUNDO_H
