#pragma once
#include "nodoD.h";
class listaDobleCircular
{
private:
	nodoD* cab;
	int largo;

public:
	listaDobleCircular();
	~listaDobleCircular();

	nodoD* getCab();
	int getLargo();

	void setCab(nodoD*);
	void setLargo(int);

	bool esVacia();

	nodoD* dirNodo(int);
	nodoD* dirUltimo();
	nodoD* dirAnte(int);
	nodoD* dirNodoPos(int);

	void agregarInicio(int);
	void agregarFinal(int);
	bool agregarAntesDe(int, int);
	bool agregarDespuesDe(int, int);
	bool agregarPos(int, int);

	bool remover(int);
	bool removerPos(int);

	void desplegar();
	void desplegarMultiplos(int n);
	void xEnLista(int n);
	listaDobleCircular* listaInvertida();
};

