#include "listaDobleLineal.h"
#include <iostream>

nodoD* listaDobleLineal::dirAnterior(int x)
{
	nodoD* ant = dirNodo(x);
	if (ant == NULL)
		return NULL;
	else
		return ant->getAnte();
}

nodoD* listaDobleLineal::dirUltimo()
{
	if (largo == 0) {
		return NULL;
	}
	nodoD* aux = cab;

	while (aux->getSgte() != NULL) {

		aux = aux->getSgte();
	}
	return aux;
}

bool listaDobleLineal::agregarDespuesDe(int x, int ref)
{
	nodoD* aux = dirNodo(ref);
	if (!esVacia() && aux != NULL) {
		nodoD* nuevo = new nodoD(x); //Paso 1
		nuevo->setAnte(aux); //Paso 2
		nuevo->setSgte(aux->getSgte());
		if (aux->getSgte() != NULL) {
			aux->getSgte()->setAnte(nuevo);
		}
		aux->setSgte(nuevo);//Ultima instruccion
		largo++;
		return true;
	}
	return false;	
}

void listaDobleLineal::agregarFinal(int x)
{
	if (esVacia()==true) {
		agregarInicio(x);
	}
	else
	{
		nodoD* nuevo = new nodoD(x);
		nodoD* aux = dirUltimo();
		aux->setSgte(nuevo);
		nuevo->setAnte(aux);
		largo++;
	}
}

nodoD* listaDobleLineal::dirNodoIndice(int n)
{
	if (n > largo) {
		return NULL;
	}
	else
	{
		int contador = 0;
		nodoD* aux = cab;
		while (contador != n) {
			aux = aux->getSgte();
			contador++;
		}
		return aux;
	}
}

int listaDobleLineal::valorIndice(int n)
{
	if (dirNodoIndice(n) == NULL) {
		return 0;
	}
	else
	{
		nodoD* nodito = dirNodoIndice(n);
		return nodito->getDato();
	}
}

bool listaDobleLineal::agregarIndice(int agregado, int n)
{
	if (dirNodoIndice(n) == NULL) {
		return false;
	}
	else {
		nodoD* nodito = dirNodoIndice(n);
		agregarAntesDe(agregado, nodito->getDato());
		return true;
	}
}

bool listaDobleLineal::eliminarIndice(int n)
{
	if (dirNodoIndice(n) == NULL) {
		return false;
	}
	else
	{
		nodoD* nodito = dirNodoIndice(n);
		eliminar(nodito->getDato());
		return true;
	}
}

bool listaDobleLineal::eliminar(int x)
{
	bool removido = true;
	nodoD* aux;
	if (!esVacia())

		if (getCab()->getDato() == x) {
			aux = getCab();
			setCab(aux->getSgte());
			cab->setAnte(NULL);
			delete aux;
			largo--;
			removido = true;
		}
		else {
			nodoD* ant = dirAnterior(x);
			if (ant != NULL) {
				aux = ant->getSgte();
				if (aux->getSgte() != NULL) {
					ant->setSgte(aux->getSgte());
					aux->getSgte()->setAnte(ant);
				}
				delete aux;
				largo--;
				removido = true;
			}

		}

	return removido;
}

void listaDobleLineal::agregarInicio(int x)
{
	nodoD* nuevo = new nodoD(x);
	nuevo->setSgte(getCab());
	if (cab != NULL) {
		getCab()->setAnte(nuevo);
	}
		setCab(nuevo);
	largo++;
}

bool listaDobleLineal::agregarAntesDe(int x, int ref)
{
	nodoD* aux = dirNodo(ref);
	if (aux != NULL) {
		if (ref == cab->getDato()) {
			agregarInicio(x);
			return true;
		}
		else
		{
				nodoD* nuevo = new nodoD(x);
				nuevo->setSgte(aux);
				nuevo->setAnte(aux->getAnte());
				aux->getAnte()->setSgte(nuevo);
				aux->setAnte(nuevo);
				largo++;
				return true;

		}
		return false;
	}
}

bool listaDobleLineal::esVacia()
{
	if (largo == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

nodoD* listaDobleLineal::dirNodo(int x)
{
	nodoD* aux = getCab();
	bool encontrado = false;
	if (aux->getDato() == x) {
		encontrado = true;
		return aux;
	}
	else
	{
		while (aux->getSgte() != NULL)
		{
			if (aux->getSgte()->getDato() == x) {
				return aux->getSgte();
				encontrado = true;
			}
			aux = aux->getSgte();
		}
	}
	if (encontrado == false)
	{
		return NULL;
	}
}

listaDobleLineal::listaDobleLineal()
{
	this->cab = NULL;
	this->largo = 0;
}

listaDobleLineal::~listaDobleLineal()
{
}

int listaDobleLineal::getLargo()
{
	return largo;
}

nodoD* listaDobleLineal::getCab()
{
	return cab;
}

void listaDobleLineal::setLargo(int l)
{
	this->largo = l;
}

void listaDobleLineal::setCab(nodoD* n)
{
	this->cab = n;
}

void listaDobleLineal::desplegar()
{
	nodoD* aux = getCab();
	while (aux != NULL)
	{
		cout << aux->getDato() << endl;
		aux = aux->getSgte();
	}
}
