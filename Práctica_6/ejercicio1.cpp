#include <iostream>
#include <vector>
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



	Coordenada c1(5, 1);
	Coordenada c2(5, 7);
	Coordenada c3(8, 9);
	Coordenada c4(-3, -2);
	Coordenada c5(-8, 3);


	PoligonoIrreg p1;

	p1.anadeVertice(c1);
	p1.anadeVertice(c2);
	p1.anadeVertice(c3);
	p1.anadeVertice(c4);
	p1.anadeVertice(c5);

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

void PoligonoIrreg::anadeVertice(Coordenada c){
	v.push_back(c);
}

void PoligonoIrreg::imprimeVertice(){
	for(Coordenada c:v){
		cout << c.obtenerX() << ", " << c.obtenerY() << endl;
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