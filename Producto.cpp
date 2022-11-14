#include "Producto.h"

Producto::Producto(char *_codigo,float precio,char *_nombre,char *_descripcion)
{
	strcpy(codigo, _codigo);
	this->precio = precio;
	strcpy(nombre, _nombre);
	strcpy(descripcion, _descripcion);
	cantidad = 0;
}
Producto::Producto()
{	
}
Producto::~Producto()
{
}
	//sets
void Producto::setCodigo(char *_codigo)
{
	strcpy(codigo, _codigo);
}
void Producto::setPrecio(float precio)
{
	this->precio = precio;
}
void Producto::setNombre(char *_nombre)
{
	strcpy(nombre, _nombre);
}
void Producto::setDescripcion(char *_descripcion)
{
	strcpy(descripcion, _descripcion);
}
void Producto::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}
	//gets
char *Producto::getCodigo()
{
	return codigo;
}
float Producto::getPrecio()
{
	return precio;
}
char *Producto::getNombre()
{
	return nombre;
}
char *Producto::getDescripcion()
{
	return descripcion;
}
int Producto::getCantidad()
{
	return cantidad;
}
bool Producto::restarInventario(int resta)
{
	if((cantidad-resta)>=0)
	{
		cantidad-=resta;
		return true;
	}
	else
	{
		cout<<"!!!! CANTIDAD INSUFICIENTE EN EL INVENTARIO !!!!"<<endl;
		return false;
	}
}
void Producto::cantidadFactura(int resta)
{
	cantidad = resta;
}
void Producto::sumarInventario(int suma)
{
	cantidad+=suma;
}
bool Producto::compararCantidad(int resta)
{
	if((cantidad-resta)>=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
