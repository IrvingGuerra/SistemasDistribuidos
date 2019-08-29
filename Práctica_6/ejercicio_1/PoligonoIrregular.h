#ifndef POLIGONO_IRREGULAR_H_
#define POLIGONO_IRREGULAR_H_

#include <iostream>
#include <vector>
#include "Coordenada.h"

using namespace std;

class PoligonoIrregular
{
private:
	vector<Coordenada> vertices;
public:
	void anadeVerticesPush(int);
	void anadeVerticesReserve(int);
	void imprimeVertices();
	vector<Coordenada> obtieneVertices();
	static int cuentaVertices;
	static bool compara(Coordenada, Coordenada);
};

#endif