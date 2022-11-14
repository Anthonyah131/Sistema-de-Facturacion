#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string.h>

using namespace std;

class Cliente
{
	private:
		char cedula[40];
		char nombre[40];
		char direccion[40];
	public:
		Cliente(char*,char*,char*);
		Cliente();
		~Cliente();
		void setCedula(char*);
		void setNombre(char*);
		void setDireccion(char*);
		char *getCedula();
		char *getNombre();
		char *getDireccion();
		void leeOrac(char*);
};

#endif
