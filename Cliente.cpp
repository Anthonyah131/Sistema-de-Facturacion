#include "Cliente.h"

Cliente::Cliente(char *_cedula,char *_nombre,char *_direccion)
{
	strcpy(cedula, _cedula);
	strcpy(nombre, _nombre);
	strcpy(direccion, _direccion);
}
Cliente::Cliente()
{
}
Cliente::~Cliente()
{
}
	//sets
void Cliente::setCedula(char *_cedula)
{
	strcpy(cedula, _cedula);
}
void Cliente::setNombre(char *_nombre)
{
	strcpy(nombre, _nombre);
}
void Cliente::setDireccion(char *_direccion)
{
	strcpy(direccion, _direccion);
}
	//gets
char *Cliente::getCedula()
{
	return cedula;
}
char *Cliente::getNombre()
{
	return nombre;
}
char *Cliente::getDireccion()
{
	return direccion;
}
