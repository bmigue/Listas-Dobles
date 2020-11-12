#pragma once
#include "nodoD.h";
#include <iostream>

class listaDobleLineal
{
private:
	nodoD* cab;
	int largo;
public:
	listaDobleLineal();
	~listaDobleLineal();
	int getLargo(); //igual a LS
	nodoD* getCab();// ILS
	void setLargo(int);//ILS
	void setCab(nodoD*);//ILS
	void desplegar();//ILS
	void agregarInicio(int x);
	bool agregarAntesDe(int x, int ref);
	bool esVacia();
	nodoD* dirNodo(int);//ILS
	nodoD* dirAnterior(int);
	nodoD* dirUltimo();//ILS
	bool agregarDespuesDe(int x, int y);
	void agregarFinal(int x);
	nodoD* dirNodoIndice(int n);
	int valorIndice(int n);
	bool agregarIndice(int agregado, int n);
	bool eliminarIndice(int n);
	bool eliminar(int x);
};

