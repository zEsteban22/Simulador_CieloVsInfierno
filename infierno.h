#ifndef INFIERNO_H
#define INFIERNO_H
#include "avlfamilia.h"
#include "mundo.h"
#include <QVector>
#include <QtAlgorithms>

bool mayorQue(QPair<Persona*,int>const&e1,QPair<Persona*,int>const&e2);
struct ordenaHeap{
		int i;
		ordenaHeap(int i);
		bool operator()(QPair<QString,avlFamilia>const&e1,QPair<QString,avlFamilia>const&e2);
};
bool ordenaQueue(Persona*e1,Persona*e2);
QQueue<Persona*>::iterator insert_sorted( QQueue<Persona*> & queue, Persona* const& item);

struct Infierno
{
		QVector<QPair<QString,avlFamilia>> familiasPorPecado[7];
		std::string nombresDemonios[7];
		string condenar(Mundo mundo);
		void aniadirAlInfierno(QVector<QPair<QString,avlFamilia>>*heap,Persona*p);
		QQueue<Persona*>*getMenosPecadores();
		void mostrarDemonios();
		int cantidadDeHumanos();
		int promedioDePecados();
		int cantMaxPecados();
		int cantMinPecados();
		void estadisticaInfierno();
		int**sumaAcciones(){
			static int acciones[2][7]={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
			QQueue<nodoPersona*>restantes;
			nodoPersona*persona;
			for(int i=0;i<7;i++)
				for(QPair<QString,avlFamilia> familia:familiasPorPecado[i]){
					persona=familia.second.r;
					while(persona!=nullptr||!restantes.isEmpty()){
						if (persona!=nullptr){
							restantes.enqueue(persona->l);
							restantes.enqueue(persona->r);
							for(int j=0;j<7;j++){
								acciones[0][j]+=persona->d->pecados[j];
								acciones[1][j]+=persona->d->virtudes[j];
							}
						}
						persona=restantes.dequeue();
					}
				}
			return (int**)acciones;
		}
		Infierno();
};

#endif // INFIERNO_H
