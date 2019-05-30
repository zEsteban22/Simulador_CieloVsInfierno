#ifndef ARBOLDEANGELES_H
#define ARBOLDEANGELES_H

#include "nodoangel.h"
#include <QQueue>


struct ArbolDeAngeles
{
		NodoAngel*dios;
		int altura;
		NodoAngel* insertar(Persona*p,NodoAngel*s,std::string n);
		ArbolDeAngeles();
		QQueue<NodoAngel*>getUltimoNivel(){
			QQueue<NodoAngel*>q;
			NodoAngel*temp=dios;
			while(temp->hijo1!=nullptr){
				q.enqueue(temp->hijo1);
				q.enqueue(temp->hijo2);
				q.enqueue(temp->hijo3);
				temp=q.dequeue();
			}
			return q;
		}
};

#endif // ARBOLDEANGELES_H
