#include "avlcielo.h"

int avlCielo::height(nodoCielo *t) {
	 int h = 0;
	 if (t != NULL) {
			int l_height = height(t->l);
			int r_height = height(t->r);
			int max_height = max(l_height, r_height);
			h = max_height + 1;
	 }
	 return h;
}
int avlCielo::difference(nodoCielo *t) {
	 int l_height = height(t->l);
	 int r_height = height(t->r);
	 int b_factor = l_height - r_height;
	 return b_factor;
}
nodoCielo *avlCielo::rr_rotat(nodoCielo *parent) {
	 nodoCielo *t;
	 t = parent->r;
	 parent->r = t->l;
	 t->l = parent;
	 return t;
}
nodoCielo *avlCielo::ll_rotat(nodoCielo *parent) {
	 nodoCielo *t;
	 t = parent->l;
	 parent->l = t->r;
	 t->r = parent;
	 return t;
}
nodoCielo *avlCielo::lr_rotat(nodoCielo *parent) {
	 nodoCielo *t;
	 t = parent->l;
	 parent->l = rr_rotat(t);
	 return ll_rotat(parent);
}
nodoCielo *avlCielo::rl_rotat(nodoCielo *parent) {
	 nodoCielo *t;
	 t = parent->r;
	 parent->r = ll_rotat(t);
	 return rr_rotat(parent);
}
nodoCielo *avlCielo::balance(nodoCielo *t) {
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

nodoCielo*avlCielo::insert(Persona*d, NodoAngel*salvador){
	return insert(r,d,salvador);
}

nodoCielo*avlCielo::get(int d) const{
	return get(d,r);
}

nodoCielo*avlCielo::get(int id, nodoCielo*r) const{
	if (r==nullptr)
		return nullptr;
	else if(r->d->id==id)
		return r;
	else if (r->d->id<id)
		return get(id,r->l);
	else
		return get(id,r->r);
}
nodoCielo *avlCielo::insert(nodoCielo *r, Persona* v,NodoAngel*salvador) {
	if (r == NULL) {
		r = new nodoCielo;
		r->d = v;
		r->l = NULL;
		r->r = NULL;
		r->salvador=salvador;
		return r;
	} else if (v< r->d) {
			r->l = insert(r->l, v,salvador);
			r = balance(r);
	 } else if (v >= r->d) {
			r->r = insert(r->r, v,salvador);
			r = balance(r);
	 } return r;
}

QVector<int>avlCielo::suma(bool pecados) const{
	QVector<int> salida;
	QQueue<nodoCielo*>restantes;
	nodoCielo*nodo=r;
	QVector<int>a(8);
	int*arr;
	while(nodo!=nullptr){
		restantes.enqueue(nodo->l);
		restantes.enqueue(nodo->r);
		a.clear();
		arr=pecados?nodo->d->pecados:nodo->d->virtudes;
		copy(arr,arr+8,back_inserter(a));
		sumaDeArrays(&salida,&a);
		nodo=restantes.dequeue();
	}
	return salida;
}

QVector<int>avlCielo::sumaPecados() const{
	return suma(true);
}

QVector<int>avlCielo::sumaVirtudes() const{
	return suma(false);

}
string avlCielo::inorder(int i){
	return inorder(r,i);
}
string avlCielo::inorder(nodoCielo *t,int i,string s) {
	if (t == NULL)
		return "";
	s+=inorder(t->l,i,s);
	s+=t->d->to_string(i)+" ";
	s+=inorder(t->r,i,s);
	return s;
}

avlCielo::avlCielo() {
	r = NULL;
}
