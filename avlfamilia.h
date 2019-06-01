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
struct nodoPersona {
	 Persona*d;
	 nodoPersona *l;
	 nodoPersona *r;
	 nodoPersona(Persona*p=nullptr);
};

struct avlFamilia {
		nodoPersona *r;
		int height(nodoPersona *);
		int difference(nodoPersona *);
		nodoPersona *rr_rotat(nodoPersona *);
		nodoPersona *ll_rotat(nodoPersona *);
		nodoPersona *lr_rotat(nodoPersona*);
		nodoPersona *rl_rotat(nodoPersona *);
		nodoPersona * balance(nodoPersona *);
		nodoPersona*insert(Persona* d);
		nodoPersona*get(int d)const;
		nodoPersona*get(int id, nodoPersona*r)const;
		nodoPersona * insert(nodoPersona*, Persona*);
		QVector<int>suma(bool pecados)const;
		QVector<int>sumaPecados()const;
		QVector<int>sumaVirtudes()const;
		string inorder(int i=0);
		string inorder(nodoPersona*,int i,string s="");
		avlFamilia();
		avlFamilia(Persona*p);
};
#endif // AVL_H
