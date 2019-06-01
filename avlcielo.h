#ifndef AVLCIELO_H
#define AVLCIELO_H
#include<iostream>
#include"persona.h"
#include"nodoangel.h"
#include<QQueue>
using namespace std;
struct nodoCielo{
		Persona*d;
		nodoCielo*l;
		nodoCielo*r;
		NodoAngel*salvador;
};
struct avlCielo {
		nodoCielo *r;
		int height(nodoCielo *);
		int difference(nodoCielo *);
		nodoCielo *rr_rotat(nodoCielo *);
		nodoCielo *ll_rotat(nodoCielo *);
		nodoCielo *lr_rotat(nodoCielo*);
		nodoCielo *rl_rotat(nodoCielo *);
		nodoCielo * balance(nodoCielo *);
		nodoCielo*insert(Persona* d,NodoAngel*salvador);
		nodoCielo*get(int d)const;
		nodoCielo*get(int id, nodoCielo*r)const;
		nodoCielo * insert(nodoCielo*, Persona*,NodoAngel*);
		QVector<int> suma(bool pecados)const;
		QVector<int>sumaPecados()const;
		QVector<int>sumaVirtudes()const;
		string inorder(int i=0);
		string inorder(nodoCielo*,int i,string s="");
		avlCielo();
};
#endif // AVLCIELO_H
