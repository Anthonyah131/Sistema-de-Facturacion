#ifndef NODOF_H
#define NODOF_H
#include "Factura.h"

class NodoF
{
	private:
		Factura *Dato;
		NodoF *sig;
		NodoF *ant;
		
	public:
		NodoF(NodoF*, Factura*, NodoF*);
		NodoF(Factura*);
		~NodoF();
		void setDato(Factura*);
		void setSig(NodoF*);
		void setAnt(NodoF*);
		Factura *getDato();
		NodoF *getSig();
		NodoF *getAnt();
};

#endif
