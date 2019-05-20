#ifndef AVL_H
#define AVL_H

#include "persona.h"
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<QQueue>
#define pow2(n) (1 << (n))
using namespace std;
void sumaDeArrays(int arr1[8],int arr2[8]){
	for (int i=0;i<8;i++)
		arr1[i]+=arr2[i];
}
struct avl {
	 Persona*d;
	 avl *l;
	 avl *r;
};
struct avl_tree {
		avl *r;
		int height(avl *);
		int difference(avl *);
		avl *rr_rotat(avl *);
		avl *ll_rotat(avl *);
		avl *lr_rotat(avl*);
		avl *rl_rotat(avl *);
		avl * balance(avl *);
		avl*insert(Persona* d){
			return insert(r,d);
		}
		avl*get(int d){
			return get(d,r);
		}
		avl*get(int id, avl*r){
			if (r==nullptr)
				return nullptr;
			else if(r->d->id==id)
				return r;
			else if (r->d->id<id)
				return get(id,r->l);
			else
				return get(id,r->r);
		}
		avl * insert(avl*, Persona*);
		int* suma(bool pecados){
			static int salida[8]={0,0,0,0,0,0,0,0};
			QQueue<avl*>restantes;
			avl*nodo=r;
			while(nodo!=nullptr){
				restantes.enqueue(nodo->l);
				restantes.enqueue(nodo->r);
				sumaDeArrays(salida,pecados?nodo->d->pecados:nodo->d->virtudes);
				nodo=restantes.dequeue();
			}
			return salida;
		}
		int* sumaPecados(){
			return suma(true);
		}
		int* sumaVirtudes(){
			return suma(false);

		}
		avl_tree() {
			r = NULL;
		}
};
#endif // AVL_H
