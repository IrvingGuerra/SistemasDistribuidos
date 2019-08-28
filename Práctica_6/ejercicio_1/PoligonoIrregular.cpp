#include "PoligonoIrregular.h"
using namespace std;

void PoligonoIrregular::anadeVerticesPush(int noVertices)
{
	for (int i = 0; i < noVertices; i++)
	{
		vertices.push_back(Coordenada(rand() % 100 / 10.0, rand() % 100 / 10.0));
	}
	cuentaVertices += noVertices;
}
void PoligonoIrregular::anadeVerticesReserve(int noVertices)
{
	vertices.reserve(noVertices);
	for (int i = 0; i < noVertices; i++)
	{
		vertices[i] = Coordenada(rand() % 100 / 10.0, rand() % 100 / 10.0);
	}
	cuentaVertices += noVertices;
}
void PoligonoIrregular::imprimeVertices()
{
	for (int i = 0; i < vertices.size(); i++)
	{
		cout << "X(" << i << "): " << vertices[i].obtenerX() << ", Y(" << i << "): " << vertices[i].obtenerY() << endl;
	}
}
int PoligonoIrregular::cuentaVertices = 0;
