#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


class Coordenada {
	private:
	double x;
	double y;
	public:
	Coordenada(double = 0, double = 0);
	double obtenerX();
	double obtenerY();
};


class PoligonoIrreg{
	private:
	vector<Coordenada> v;
	public:
	void anadeVertice(Coordenada c);
	void imprimeVertice();
	void anadeVerticesPush(int);
	static int cuentaVertices;
};

class Rectangulo {
	private:
	Coordenada superiorIzq;
	Coordenada inferiorDer;
	public:
	Rectangulo();
	Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
	void imprimeEsq();
	Coordenada obtieneSupIzq();
	Coordenada obtieneInfDer();
};

int main( ) {
	Rectangulo rectangulo1(2,3,5,1);
	double ancho, alto;
 
	cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";
	rectangulo1.imprimeEsq();

	alto = rectangulo1.obtieneSupIzq().obtenerY() -
	rectangulo1.obtieneInfDer().obtenerY();
	ancho = rectangulo1.obtieneInfDer().obtenerX() -
	rectangulo1.obtieneSupIzq().obtenerX();
	cout << "El área del rectángulo es = " << ancho*alto << endl;



	PoligonoIrreg p1;

	p1.anadeVerticesPush(1000);

	p1.imprimeVertice();

	return 0;
}

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
{ }

double Coordenada::obtenerX() {
	return x;
}

double Coordenada::obtenerY() {
	return y;
}

void PoligonoIrreg::anadeVerticesPush(int noVertices)
{
	for (int i = 0; i < noVertices; i++)
	{
		v.push_back(Coordenada(rand() % 100000 / 1000.0 * pow(-1, rand()), rand() % 100000 / 1000.0 * pow(-1, rand())));
	}
	cuentaVertices += noVertices;
}

int PoligonoIrreg::cuentaVertices = 0;

void PoligonoIrreg::anadeVertice(Coordenada c){
	v.push_back(c);
}


void PoligonoIrreg::imprimeVertice(){

	std::vector<Coordenada>::iterator i;
	for(i = v.begin(); i != v.end(); i++){
		double x = (*i).obtenerX();
		double y = (*i).obtenerY();
		double magnitud = sqrt(pow(x, 2.0)+pow(y, 2.0));
		cout << x << ", " << y << ", magnitud: " << magnitud << endl;
	}
}

Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0)
{ }

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double
yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{ }

void Rectangulo::imprimeEsq() {
	cout << "Para la esquina superior izquierda.\n";
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
	cout << "Para la esquina inferior derecha.\n";
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}
Coordenada Rectangulo::obtieneSupIzq() {
	return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer() {
	return inferiorDer;
}