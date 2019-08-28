#include "Coordenada.h"
#include <iostream>
using namespace std;


Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){ }

// Coordenada::Coordenada(double r, double theta) {
// 	x = r * cos(theta);
// 	y = r * sin(theta);
// }
 
double Coordenada::obtenerX(){
	return x;
}

double Coordenada::obtenerY(){
	return y;
}