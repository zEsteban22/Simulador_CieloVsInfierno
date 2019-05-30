#include "avlfamilia.h"

int avlFamilia::height(nodoPersona *t) {
	 int h = 0;
	 if (t != NULL) {
			int l_height = height(t->l);
			int r_height = height(t->r);
			int max_height = max(l_height, r_height);
			h = max_height + 1;
	 }
	 return h;
}
int avlFamilia::difference(nodoPersona *t) {
	 int l_height = height(t->l);
	 int r_height = height(t->r);
	 int b_factor = l_height - r_height;
	 return b_factor;
}
nodoPersona *avlFamilia::rr_rotat(nodoPersona *parent) {
	 nodoPersona *t;
	 t = parent->r;
	 parent->r = t->l;
	 t->l = parent;
	 cout<<"Right-Right Rotation";
	 return t;
}
nodoPersona *avlFamilia::ll_rotat(nodoPersona *parent) {
	 nodoPersona *t;
	 t = parent->l;
	 parent->l = t->r;
	 t->r = parent;
	 cout<<"Left-Left Rotation";
	 return t;
}
nodoPersona *avlFamilia::lr_rotat(nodoPersona *parent) {
	 nodoPersona *t;
	 t = parent->l;
	 parent->l = rr_rotat(t);
	 cout<<"Left-Right Rotation";
	 return ll_rotat(parent);
}
nodoPersona *avlFamilia::rl_rotat(nodoPersona *parent) {
	 nodoPersona *t;
	 t = parent->r;
	 parent->r = ll_rotat(t);
	 cout<<"Right-Left Rotation";
	 return rr_rotat(parent);
}
nodoPersona *avlFamilia::balance(nodoPersona *t) {
	 int bal_factor = difference(t);
	 if (bal_factor > 1) {
			if (difference(t->l) > 0)
				 t = ll_rotat(t);
			else
				 t = lr_rotat(t);
	 } else if (bal_factor < -1) {
			if (difference(t->r) > 0)
				 t = rl_rotat(t);
			else
				 t = rr_rotat(t);
	 }
	 return t;
}

nodoPersona*avlFamilia::insert(Persona*d){
	return insert(r,d);
}

nodoPersona*avlFamilia::get(int d) const{
	return get(d,r);
}

nodoPersona*avlFamilia::get(int id, nodoPersona*r) const{
	if (r==nullptr)
		return nullptr;
	else if(r->d->id==id)
		return r;
	else if (r->d->id<id)
		return get(id,r->l);
	else
		return get(id,r->r);
}
nodoPersona *avlFamilia::insert(nodoPersona *r, Persona* v) {
	if (r == NULL) {
		r = new nodoPersona;
		r->d = v;
		r->l = NULL;
		r->r = NULL;
		return r;
	} else if (v< r->d) {
		r->l = insert(r->l, v);
		r = balance(r);
	 } else if (v >= r->d) {
			r->r = insert(r->r, v);
			r = balance(r);
	 } return r;
}

int*avlFamilia::suma(bool pecados) const{
	static int salida[8]={0,0,0,0,0,0,0,0};
	QQueue<nodoPersona*>restantes;
	nodoPersona*nodo=r;
	while(nodo!=nullptr){
		restantes.enqueue(nodo->l);
		restantes.enqueue(nodo->r);
		sumaDeArrays(salida,pecados?nodo->d->pecados:nodo->d->virtudes);
		nodo=restantes.dequeue();
	}
	return salida;
}

int*avlFamilia::sumaPecados() const{
	return suma(true);
}

int*avlFamilia::sumaVirtudes() const{
	return suma(false);

}
string avlFamilia::inorder(int i){
	return inorder(r,i);
}
string avlFamilia::inorder(nodoPersona *t,int i,string s) {
	if (t == NULL)
		return "";
	s+=inorder(t->l,i,s);
	s+=t->d->to_string(i)+" ";
	s+=inorder(t->r,i,s);
	return s;
}

avlFamilia::avlFamilia() {
	r = NULL;
}

avlFamilia::avlFamilia(Persona*p):r(new nodoPersona(p)){
}

nodoPersona::nodoPersona(Persona*p):d(p),l(nullptr),r(nullptr){}
