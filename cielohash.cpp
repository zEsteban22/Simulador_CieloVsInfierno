#include "cielohash.h"


CieloHash::CieloHash(){
}

int CieloHash::hashFunction(int value){
	return value%1000;
}

Persona*CieloHash::operator[](int key){
	avlCielo*tree=tablaDeHash[hashFunction(key)];
	if (tree==nullptr)
		tree=new avlCielo;
	nodoCielo*nodo=tree->get(key);
	if (nodo==nullptr)
		return nullptr;
	return nodo->d;
}

void CieloHash::mostrar(string s){
	cout<<s;
}

void CieloHash::insertar(int key, Persona*value, NodoAngel*salvador){
	avlCielo**tree=&tablaDeHash[hashFunction(key)];
	if (*tree==nullptr)
		(*tree)=new avlCielo;
	(**tree).insert(value,salvador);
}

void CieloHash::recorrerCielo(){
	for (int i=0;i<1000;i++)
		if ( tablaDeHash[i]!=nullptr)
			cout<<"Hashed key :"+to_string(i)+"\nValue:\n"+ tablaDeHash[i]->inorder(1)<<endl;
}
