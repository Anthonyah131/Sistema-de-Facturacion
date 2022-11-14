#ifndef NODOP_H
#define NODOP_H
#include "Producto.h"

class NodoP
{
	private:
		Producto *Dato;
		NodoP *sig;
		NodoP *ant;
		
	public:
		NodoP(NodoP*, Producto*, NodoP*);
		NodoP(Producto*);
		~NodoP();
		void setDato(Producto*);
		void setSig(NodoP*);
		void setAnt(NodoP*);
		Producto *getDato();
		NodoP *getSig();
		NodoP *getAnt();
};

#endif
