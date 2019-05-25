#ifndef CIELOHASH_H
#define CIELOHASH_H
#include"infierno.h"
#include "nodoangel.h"
#include"avlcielo.h"

struct CieloHash
{
		avlCielo*tablaDeHash[1000];
		CieloHash();
		int hashFunction(int value);
		Persona* operator[](int key);
		void mostrar(string s);
		void insertar(int key,Persona*value,NodoAngel*salvador);
		void recorrerCielo();
};

#endif // CIELOHASH_H
