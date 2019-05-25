#include "infierno.h"


bool mayorQue(const QPair<Persona*, int>&e1, const QPair<Persona*, int>&e2){
	return e1.second>e2.second;
}

ordenaHeap::ordenaHeap(int i):i(i){}

bool ordenaHeap::operator()(const QPair<QString, avlFamilia>&e1, const QPair<QString, avlFamilia>&e2){
	return e1.second.sumaPecados()[i]>e2.second.sumaPecados()[i];
}

bool ordenaQueue(Persona*e1, Persona*e2){
	return e1->pecados[7]-e1->virtudes[7]>e2->pecados[7]-e2->virtudes[7];
}

void Infierno::condenar(Mundo mundo){
	QVector<QPair<Persona*,int>>vector;
	for (int i=0;i<7;i++){
		for (NodoLista *temp=mundo.lista.primero();temp!=nullptr;temp=temp->siguiente){
			QPair<Persona*,int>par(temp->persona,
														 temp->persona->pecados[i]-temp->persona->virtudes[i]);
			vector.insert(lower_bound(vector.begin(),vector.end(),par,mayorQue),par);
		}
		for(int j=0;j<vector.size()*0.05;j++)
			aniadirAlInfierno(&familiasPorPecado[i],mundo.eliminar(vector[j].first));
		sort(familiasPorPecado[i].begin(),familiasPorPecado[i].end(),ordenaHeap(i));
		vector.clear();
	}
}

void Infierno::aniadirAlInfierno(QVector<QPair<QString, avlFamilia> >*heap, Persona*p){
	bool flag=true;
	for(QPair<QString,avlFamilia>i:*heap)
		if (i.first.toStdString()==p->apellido+"-"+p->pais){
			i.second.insert(p);
			flag=false;
		}
	if(flag)
		heap->append(QPair<QString,avlFamilia>(QString::fromStdString(p->apellido+"-"+p->pais),
																				 avlFamilia(p)));
}

QQueue<Persona*>*Infierno::getMenosPecadores(){
	QQueue<Persona*>*menosPecadores=new QQueue<Persona*>;
	QQueue<nodoPersona*>nodosDelArbol;
	nodoPersona*temp;
	for (QVector<QPair<QString,avlFamilia>>vec:familiasPorPecado)
		for (QPair<QString,avlFamilia>par:vec){
			temp=par.second.r;
			while (temp!=nullptr){
				insert_sorted(*menosPecadores,temp->d);
				nodosDelArbol.enqueue(temp->l);
				nodosDelArbol.enqueue(temp->r);
				temp=nodosDelArbol.dequeue();
			}
		}
	return menosPecadores;
}
QQueue<Persona*>::iterator insert_sorted(QQueue<Persona*>&queue, Persona*const&item){
	return queue.insert(std::lower_bound(queue.begin(), queue.end(), item, ordenaQueue),item);
}
Infierno::Infierno():familiasPorPecado{
											 QVector<QPair<QString,avlFamilia>>(),QVector<QPair<QString,avlFamilia>>(),
											 QVector<QPair<QString,avlFamilia>>(),QVector<QPair<QString,avlFamilia>>(),
											 QVector<QPair<QString,avlFamilia>>(),QVector<QPair<QString,avlFamilia>>(),
											 QVector<QPair<QString,avlFamilia>>()},
											 nombresDemonios{"Lucifer","Belcebú","Satán","Abadón","Mammón","Belfegor","Asmodeo"}{

											 }

