#ifndef FACTURA_H
#define FACTURA_H
#include <iostream>
#include <sstream>
#include <string.h>
#include <Windows.h>
#include "NodoP.h"

using namespace std;

class Factura
{	
	public:
		NodoP *listaPro;
		char cedula[40];
		char nombreC[40];
		char direccion[40];
		int nFactura;
		
		Factura(int, NodoP*, char*, char*, char*);
		Factura();
		~Factura();
		void verFactura();
		void ubicarCursor(int, int);
		void guardar();
		void recuperar();
		void eliminarListaP();
		void agregarP(NodoP*);
};

#endif
