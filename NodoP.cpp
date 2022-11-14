#include "NodoP.h"

NodoP::NodoP(NodoP *ant, Producto *Dato, NodoP *sig)
{
	this->ant = ant;
	this->Dato = Dato;
	this->sig = sig;
}
NodoP::NodoP(Producto *Dato)
{
	this->Dato = Dato;
	sig = NULL;
	ant = NULL;
}
NodoP::~NodoP()
{
}
void NodoP::setDato(Producto *Dato)
{
	this->Dato = Dato;
}
void NodoP::setSig(NodoP *sig)
{
	this->sig = sig;
}
void NodoP::setAnt(NodoP *ant)
{
	this->ant = ant;
}
Producto *NodoP::getDato()
{
	return Dato;
}
NodoP *NodoP::getSig()
{
	return sig;
}
NodoP *NodoP::getAnt()
{
	return ant;
}
