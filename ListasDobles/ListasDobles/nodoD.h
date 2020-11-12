#pragma once
#include <iostream>
using namespace std;

class nodoD
{
private:
	int dato;
	nodoD* ante;
	nodoD* sgte;
public:
	nodoD(int);
	~nodoD();
	int getDato();
	nodoD* getSgte();
	nodoD* getAnte();
	void setSgte(nodoD*);
	void setAnte(nodoD*);
	void setDato(int);
};

