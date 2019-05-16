#ifndef AVL_H
#define AVL_H


#include "persona.h"

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;
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
		avl*insert(int d){
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
		avl * insert(avl*, int);
		avl_tree() {
			r = NULL;
		}
};
#endif // AVL_H
