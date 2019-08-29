#ifndef COORDENADA_H_
#define COORDENADA_H_

#include <math.h>

using namespace std;

class Coordenada{
	private:
		double x;
		double y;
		double magnitud;
	public:
		Coordenada(double = 0, double = 0);
		// Coordenada(double r, double theta);
		double obtenerX();
		double obtenerY();
		double obtenerMagnitud();

};

#endif