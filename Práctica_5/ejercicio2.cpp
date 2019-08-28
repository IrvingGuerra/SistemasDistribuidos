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

int main( ) {

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
