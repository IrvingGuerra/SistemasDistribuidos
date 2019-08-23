#include "Coordenada.h"
#include "Rectangulo.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){

	Coordenada coordenada1(2,3);
	Coordenada coordenada2(5,1);

	Rectangulo rectangulo1(coordenada1,coordenada2);

	double ancho, alto;

	cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";

	rectangulo1.imprimeEsq();

	alto = rectangulo1.obtieneSupIzq().obtenerY() -
	rectangulo1.obtieneInfDer().obtenerY();

	ancho = rectangulo1.obtieneInfDer().obtenerX() -
	rectangulo1.obtieneSupIzq().obtenerX();

	cout << "El área del rectángulo es = " << rectangulo1.obtieneArea() << endl;

	return 0;
}
