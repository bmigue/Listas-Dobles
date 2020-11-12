#include "listaDobleCircular.h"

listaDobleCircular::listaDobleCircular()
{
	cab = NULL;
	largo = 0;
}

listaDobleCircular::~listaDobleCircular()
{
}

nodoD* listaDobleCircular::getCab()
{
	return this->cab;
}

int listaDobleCircular::getLargo()
{
	return this->largo;
}

void listaDobleCircular::setCab(nodoD* ptr)
{
	this->cab = ptr;
}

void listaDobleCircular::setLargo(int n)
{
	this->largo = n;
}

bool listaDobleCircular::esVacia()
{
	return largo == 0;
}

nodoD* listaDobleCircular::dirNodo(int x)
{ // Devuelve el nodo en que se ubica x,sino lo encuentra devuelve false
	if (getLargo() == 0)
		return NULL;
	else {
		nodoD* aux = getCab();
		bool encontrado = false;
		do {
			if (aux->getDato() == x)
				encontrado = true;
			else
				aux = aux->getSgte();
		} while (!encontrado && aux != getCab());

		if (encontrado)
			return aux;
		else
			return NULL;

	}
}

nodoD* listaDobleCircular::dirUltimo()
{
	if (getCab() == NULL)
		return NULL;
	else
		return getCab()->getAnte();
}

nodoD* listaDobleCircular::dirAnte(int dato)
{
	if (getCab() == NULL || getCab()->getDato() == dato)
		return NULL;
	else
		return dirNodo(dato)->getAnte();
}

nodoD* listaDobleCircular::dirNodoPos(int n)
{
	if (n < getLargo()) {
		nodoD* aux = getCab();
		for (int i = 0; i <= n; i++) {
			aux = aux->getSgte();
		}
		return aux;
	}
	else
		return NULL;
}

void listaDobleCircular::agregarInicio(int x)
{
	nodoD* nuevo = new nodoD(x);

	if (getLargo() == 0) {
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
	}
	else {
		nodoD* ult = cab->getAnte();
		nuevo->setSgte(getCab());
		nuevo->setAnte(getCab()->getAnte());
		ult->setSgte(nuevo);
		cab->setAnte(nuevo);
	}
	largo++;
	setCab(nuevo);

}

void listaDobleCircular::agregarFinal(int x)
{
	nodoD* nuevo = new nodoD(x);

	if (getLargo() == 0) {
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
		setCab(nuevo);
	}
	else {
		nodoD* ult = cab->getAnte();
		nuevo->setSgte(getCab());
		nuevo->setAnte(getCab()->getAnte());
		ult->setSgte(nuevo);
		cab->setAnte(nuevo);
	}
	largo++;

}

bool listaDobleCircular::agregarAntesDe(int x, int ref)
{
	bool agregado = false;
	if (!esVacia()) {
		if (getCab()->getDato() == ref) {
			agregarInicio(x);
			agregado = true;
		}
		else {
			nodoD* aux = dirNodo(ref);
			if (aux != NULL) {
				nodoD* ante = aux->getAnte();

				nodoD* nuevo = new nodoD(x);
				nuevo->setSgte(aux);
				nuevo->setAnte(ante);

				ante->setSgte(nuevo);
				aux->setAnte(nuevo);

				largo++;
				agregado = true;
			}

		}
	}

	return agregado;
}

bool listaDobleCircular::agregarDespuesDe(int x, int ref)
{
	bool agregado = true;
	if (!esVacia()) {
		nodoD* aux = dirNodo(ref);
		if (aux != NULL) {
			nodoD* sig = aux->getSgte();

			nodoD* nuevo = new nodoD(x);
			nuevo->setSgte(sig);
			nuevo->setAnte(aux);

			aux->setSgte(nuevo);
			sig->setAnte(nuevo);

			largo++;
			agregado = true;
		}
	}
	return agregado;
}

bool listaDobleCircular::agregarPos(int x, int referencia)
{
	bool agregado = false;
	if (!esVacia()) {
		nodoD* aux = dirNodoPos(referencia);
		if (aux != NULL) {
			agregado = agregarAntesDe(x, aux->getDato());
		}
	}
	return agregado;
}

bool listaDobleCircular::remover(int x)
{
	bool removido = false;
	nodoD* aux = dirNodo(x);
	if (aux != NULL) {
		if (getLargo() == 1) {
			setCab(NULL);
		}
		else {
			aux->getAnte()->setSgte(aux->getSgte());
			aux->getSgte()->setAnte(aux->getAnte());

			if (getCab() == aux) {
				setCab(aux->getSgte());
			}
		}

		delete aux;
		largo--;
	}
	return removido;
}

bool listaDobleCircular::removerPos(int n)
{
	nodoD* aux = new nodoD(n);
	bool removido = false;
	if (!esVacia()) {
		if (n >= 0 && n < getLargo()) {
			aux = dirNodoPos(n);
			removido=remover(aux->getDato());
		}
	}
	return removido;
}

void listaDobleCircular::desplegar()
{
	nodoD* aux = getCab();
	do {
		cout << aux->getDato() << endl;
		aux = aux->getSgte();
	} while (aux != cab);
}

void listaDobleCircular::desplegarMultiplos(int n)
{
	int contador = 0;
	if (!esVacia() && n>0) {
		nodoD* aux = cab;
		do
		{
			if (contador%n == 0) {
				cout << aux->getDato() << endl;
			}
			aux = aux->getSgte();
			contador++;
		} while (aux->getSgte()!=cab);

	}
}

void listaDobleCircular::xEnLista(int n)
{
	int contador = 0;
	if (!esVacia()) {
		nodoD* aux = cab;
		do
		{
			if (aux->getDato() == n) {
				contador++;
			}
			aux = aux->getSgte();
		} while (aux!=cab);
	}
	cout << "El valor " << n << " se encuentra " << contador << " veces" << endl;                                                                                                                                                         
}

listaDobleCircular* listaDobleCircular::listaInvertida()
{
	listaDobleCircular* lista = new listaDobleCircular();
	if (!esVacia()) {
		nodoD* aux = cab->getAnte();
		nodoD* auxInverso = lista->cab;
			for (int i = 1; i <= largo; i++) {
				auxInverso = aux;
				lista->agregarFinal(auxInverso->getDato());
				aux = aux->getAnte();
				auxInverso = auxInverso->getSgte();
			}
	}
	return lista;
}
