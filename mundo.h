#ifndef MUNDO_H
#define MUNDO_H
#include "arboldelmundo.h"
#include "avlFamilias.h"
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
		bool operator()(QPair<int*,QString> const &a, QPair<int*,QString> const &b) const;
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
		QMap<QString,int*>cantAccionesPorFamilia(bool pecados,QString pais);
		QMap<QString,int*>cantAccionesPorPais(bool pecados);
		QVector<QPair<int*,QString>>ordenar(QMap<QString,int*>cantidadAccionesPorPais,bool ascendente);
		void reporte(bool ascendente,bool pecadores,int cant);
		void imprimirResultado(QVector<QPair<int*,QString>>resultado,int cant);
		void reportePaisesMasPecadores();
		void reportePaisesMenosPecadores();
		string reporteAccionesDeCiertaFamilia(string pais,string apellido,bool pecados);
		void reportePecadosPorFamilia();
		void obrarBien();
		void reportePaisesMasBuenaGente();
		void reportePaisesMenosBuenaGente();
		void reporteVirtudesPorFamilia();
};

#endif // MUNDO_H
