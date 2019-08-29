#include "PoligonoIrregular.h"

void PoligonoIrregular::anadeVerticesPush(int noVertices)
{
	for (int i = 0; i < noVertices; i++)
	{
		vertices.push_back(Coordenada(rand() % 100000 / 1000.0 * pow(-1.0, (double)rand()),
									  rand() % 100000 / 1000.0 * pow(-1.0, (double)rand())));
	}
	cuentaVertices += noVertices;
}

void PoligonoIrregular::anadeVerticesReserve(int noVertices)
{
	vertices.reserve(noVertices);
	for (int i = 0; i < noVertices; i++)
	{
		vertices.push_back(Coordenada(rand() % 100000 / 1000.0 * pow(-1.0, (double)rand()),
									  rand() % 100000 / 1000.0 * pow(-1.0, (double)rand())));
	}
	cuentaVertices += noVertices;
}

void PoligonoIrregular::imprimeVertices(void)
{
	for (auto v = vertices.begin(); v != vertices.end(); v++)
	{
		double x = (*v).obtenerX();
		double y = (*v).obtenerY();
		cout << "X(" << v - vertices.begin() << "): " << x << ", Y(" << v - vertices.begin() << "): " << y << endl;
		cout << "Magnitud: " << (*v).obtenerMagnitud() << endl
			 << endl;
	}
}

vector<Coordenada> PoligonoIrregular::obtieneVertices(void)
{
	return vertices;
}

bool PoligonoIrregular::compara(Coordenada c1, Coordenada c2)
{
	return c1.obtenerMagnitud() < c2.obtenerMagnitud();
}

void PoligonoIrregular::ordenaVertices(void)
{
	sort(vertices.begin(), vertices.end(), compara);
}

int PoligonoIrregular::cuentaVertices = 0;
