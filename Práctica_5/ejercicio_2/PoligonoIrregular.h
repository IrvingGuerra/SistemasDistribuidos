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
	void anadeVertice();
	void imprimeVertices();
};

#endif