#include "nodoD.h"

nodoD::nodoD(int x)
{
	this->dato = x;
	this->sgte = NULL;
	this->ante = NULL;
}

nodoD::~nodoD()
{
}

int nodoD::getDato()
{
	return dato;
}

nodoD* nodoD::getSgte()
{
	return sgte;
}

nodoD* nodoD::getAnte()
{
	return ante;
}

void nodoD::setSgte(nodoD* d)
{
	this->sgte = d;
}

void nodoD::setAnte(nodoD* ante)
{
	this->ante = ante;
}

void nodoD::setDato(int dato)
{
	this->dato = dato;
}
