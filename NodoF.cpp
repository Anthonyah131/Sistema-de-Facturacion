#include "NodoF.h"

NodoF::NodoF(NodoF *ant, Factura *Dato, NodoF *sig)
{
	this->ant = ant;
	this->Dato = Dato;
	this->sig = sig;
}
NodoF::NodoF(Factura *Dato)
{
	this->Dato = Dato;
	sig = NULL;
	ant = NULL;
}
NodoF::~NodoF()
{
}
void NodoF::setDato(Factura *Dato)
{
	this->ant = ant;
}
void NodoF::setSig(NodoF *sig)
{
	this->Dato = Dato;
}
void NodoF::setAnt(NodoF *ant)
{
	this->sig = sig;
}
Factura *NodoF::getDato()
{
	return Dato;
}
NodoF *NodoF::getSig()
{
	return sig;
}
NodoF *NodoF::getAnt()
{
	return ant;
}
