#ifndef MUNDO_H
#define MUNDO_H
#include "arboldelmundo.h"
#include "avlFamilias.h"
#include <QString>
#include <iostream>
#include <QMap>

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
		string nombres[1000],apellidos[1000],paises[100],profesiones[50],creencias[10];
		string tiposPecados[7];
		ArbolDelMundo arbol;
		ListaPersonas lista;
		QVector<Persona*>personasSinPapa;
		Mundo();
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
		string reporteAccionesDeCiertaFamilia(string pais,string apellido,bool pecados){//La especificación de familia;
			string salida="Pecados de la familia "+pais+"-"+apellido+"\n";
			QQueue<nodoPersona*>restantes;
			nodoPersona*persona=familiasPorPais[QString::fromStdString(pais)][QString::fromStdString(apellido)].r;
			while(persona!=nullptr||restantes.isEmpty()){
				if(persona!=nullptr){
					restantes.enqueue(persona->l);
					restantes.enqueue(persona->r);
					salida+="Pecados de "+persona->d->nombre+" "+persona->d->apellido;
					for(int i=0;i<8;i++)
						salida+=!pecados?nombresVirtudes[i]:tiposPecados[i]+": "+to_string(pecados?persona->d->pecados[i]:persona->d->virtudes[i])+"\n";
				}
				persona=restantes.dequeue();
			}
			return salida;
		}
		void reportePecadosPorFamilia(){
			for (string p : paises) {
				for (string a: apellidos){
					cout<<reporteAccionesDeCiertaFamilia(p,a,true);
				}
			}
		}
		void obrarBien();
		void reportePaisesMasBuenaGente();
		void reportePaisesMenosBuenaGente();
		void reporteVirtudesPorFamilia(){

		}
};

#endif // MUNDO_H
