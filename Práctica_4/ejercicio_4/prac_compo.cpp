#include "Rectangulo.h"
#include "Coordenada.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){

	cout << "Inicializado con coordenadas polares r = 3.60555, theta = 0.982793" << endl;
	cout << "Inicializado con coordenadas polares r = 5.09901, theta = 0.197395" << endl;
	Rectangulo r(Coordenada(3.60555, 0.982793), Coordenada(5.09901, 0.197395));
	cout << "Area con coordenadas polares: " << r.obtieneArea() << endl;
	return 0;
}
