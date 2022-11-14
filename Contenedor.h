#ifndef CONTENEDOR_H
#define CONTENEDOR_H
#include "NodoC.h"
#include "NodoP.h"
#include "NodoF.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Contenedor
{
	private:
		NodoC *listaC;
		NodoP *listaP;
		NodoF *listaF;
		int nFactura;
		
	public:
		Contenedor();
		~Contenedor();
		void crearCliente();
		void crearProducto();
		void ingresarAlInventario();
		void crearFactura();
		void verFacturas();
		void leeOrac(char*);
		void ubicarCursor(int x, int y);
		void listadoProductos();
		void listadoClientes();
		void guardar();
		void recuperar();
		void eliminarListaC();
		void eliminarListaP();
		void eliminarListaF();
		void agregarC(NodoC*);
		void agregarP(NodoP*);
		void agregarF(NodoF*);
		void verFacturasC();
};

#endif
