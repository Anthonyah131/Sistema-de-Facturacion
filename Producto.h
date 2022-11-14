#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string.h>

using namespace std;

class Producto
{
	private:
		char codigo[40];
		float precio;
		char nombre[40];
		char descripcion[40];
		int cantidad;
		
	public:
		Producto(char*,float,char*,char*);
		Producto();
		~Producto();
		void setCodigo(char*);
		void setPrecio(float);
		void setNombre(char*);
		void setDescripcion(char*);
		void setCantidad(int);
		char* getCodigo();
		float getPrecio();
		char* getNombre();
		char* getDescripcion();
		int getCantidad();
		bool restarInventario(int);
		void cantidadFactura(int);
		void sumarInventario(int);
		bool compararCantidad(int);
};

#endif
