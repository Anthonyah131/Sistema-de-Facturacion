#ifndef NODOC_H
#define NODOC_H
#include "Cliente.h"

class NodoC
{
	private:
		Cliente *Dato;
		NodoC *sig;
		NodoC *ant;
		
	public:
		NodoC(NodoC*, Cliente*, NodoC*);
		NodoC(Cliente*);
		~NodoC();
		void setDato(Cliente*);
		void setSig(NodoC*);
		void setAnt(NodoC*);
		Cliente *getDato();
		NodoC *getSig();
		NodoC *getAnt();
};

#endif
