#ifndef MUNDO_H
#define MUNDO_H
#include "arboldelmundo.h"
#include "avlfamilia.h"
#include <QString>
#include <iostream>
#include <QMap>
#include <QFile>
#include <QTextStream>

using namespace std;
struct comparador
{
		bool ascendente;
		comparador(bool a);
		bool operator()(QPair<QVector<int>,QString> const &a, QPair<QVector<int>,QString> const &b) const;
};
struct Mundo
{
		QMap<QString,QMap<QString,avlFamilia>>familiasPorPais;
		string nombres[1000],apellidos[1000],paises[100],profesiones[50],creencias[10],tiposPecados[7],
		tiposVirtudes[7];
		QMap<string,QVector<string>>paisesPorContinente;
		ArbolDelMundo arbol;
		ListaPersonas lista;
		QVector<Persona*>personasSinPapa;
		Mundo();
		void cargarDatos();
		void insertarNuevaPersona();
		void insertarPersonas(int c);
		Persona*eliminar(Persona*p);
		void pecar();
		QMap<QString,QVector<int>>cantAccionesPorFamilia(bool pecados,QString pais);
		QMap<QString,QVector<int>>cantAccionesPorPais(bool pecados){
			QMap<QString,QVector<int>>accionesPorPais;
			QMap<QString,QVector<int>>accionesPorFamilia;
			for(auto i:familiasPorPais.keys()){
				accionesPorFamilia=cantAccionesPorFamilia(pecados,i);
				for (auto j:accionesPorFamilia)
					sumaDeArrays(&accionesPorPais[i],&j);
			}
			return accionesPorPais;
		}
		QVector<QPair<QVector<int>,QString>>ordenar(QMap<QString,QVector<int>>cantidadAccionesPorPais,bool ascendente);
		void reporte(bool ascendente,bool pecadores,int cant);
		void imprimirResultado(QVector<QPair<QVector<int>,QString>>resultado,int cant);
		void reportePaisesMasPecadores();
		void reportePaisesMenosPecadores();
		string reporteAccionesDeCiertaFamilia(string pais,string apellido,bool pecados);
		void reportePecadosPorFamilia();
		void obrarBien();
		void reportePaisesMasBuenaGente();
		void reportePaisesMenosBuenaGente();
		void reporteVirtudesPorFamilia();
		QVector<QString> reporteContinentes(bool pecados){
			QMap<QString,QVector<int>>accionesPorPais=cantAccionesPorPais(pecados);
			QMap<QString,QVector<int>>accionesPorContinente;
			string continente="";
			for(auto i:accionesPorPais.keys()){
				for (auto j:paisesPorContinente.keys()){
					if (paisesPorContinente[j].contains(i.toStdString())){
						continente=j;
						break;
					}
				}
				sumaDeArrays(&accionesPorContinente[QString::fromStdString(continente)],&accionesPorPais[i]);
			}
			QVector<QString>resultado;
			QString nombreMax;
			while(!accionesPorContinente.isEmpty()){
				nombreMax=accionesPorContinente.firstKey();
				for(auto i:accionesPorContinente.keys())
					if(accionesPorContinente[i].size()>accionesPorContinente[nombreMax].size())
						nombreMax=i;
				resultado.append(nombreMax);
				accionesPorContinente.remove(nombreMax);
			}
			return resultado;
		}
};

#endif // MUNDO_H
