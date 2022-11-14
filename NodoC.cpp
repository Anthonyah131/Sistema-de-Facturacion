#include "NodoC.h"

NodoC::NodoC(NodoC *ant, Cliente *Dato, NodoC *sig)
{
	this->ant = ant;
	this->Dato = Dato;
	this->sig = sig;
}
NodoC::NodoC(Cliente *Dato)
{
	this->Dato = Dato;
	sig = NULL;
	ant = NULL;
}
NodoC::~NodoC()
{
}
void NodoC::setDato(Cliente *Dato)
{
	this->Dato = Dato;
}
void NodoC::setSig(NodoC *sig)
{
	this->sig = sig;
}
void NodoC::setAnt(NodoC *ant)
{
	this->ant = ant;
}
Cliente *NodoC::getDato()
{
	return Dato;
}
NodoC *NodoC::getSig()
{
	return sig;
}
NodoC *NodoC::getAnt()
{
	return ant;
}
