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
	 cout<<"Right-Right Rotation";
	 return t;
}
nodoCielo *avlCielo::ll_rotat(nodoCielo *parent) {
	 nodoCielo *t;
	 t = parent->l;
	 parent->l = t->r;
	 t->r = parent;
	 cout<<"Left-Left Rotation";
	 return t;
}
nodoCielo *avlCielo::lr_rotat(nodoCielo *parent) {
	 nodoCielo *t;
	 t = parent->l;
	 parent->l = rr_rotat(t);
	 cout<<"Left-Right Rotation";
	 return ll_rotat(parent);
}
nodoCielo *avlCielo::rl_rotat(nodoCielo *parent) {
	 nodoCielo *t;
	 t = parent->r;
	 parent->r = ll_rotat(t);
	 cout<<"Right-Left Rotation";
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

int*avlCielo::suma(bool pecados) const{
	static int salida[8]={0,0,0,0,0,0,0,0};
	QQueue<nodoCielo*>restantes;
	nodoCielo*nodo=r;
	while(nodo!=nullptr){
		restantes.enqueue(nodo->l);
		restantes.enqueue(nodo->r);
		sumaDeArrays(salida,pecados?nodo->d->pecados:nodo->d->virtudes);
		nodo=restantes.dequeue();
	}
	return salida;
}

int*avlCielo::sumaPecados() const{
	return suma(true);
}

int*avlCielo::sumaVirtudes() const{
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
