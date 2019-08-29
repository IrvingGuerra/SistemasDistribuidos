#include "Coordenada.h"

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){
	magnitud = sqrt(x * x + y * y);
}

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

double Coordenada::obtenerMagnitud(){
	return magnitud;
}