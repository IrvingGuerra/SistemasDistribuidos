#include <iostream>
using namespace std;

const double gravedad = 9.8;

int main( ){
	double tiempo;
	double altura;

	cout << "\n=================== Ejercicio 2 ===================\n";
	cout << "\n=================== Caida libre ===================\n\n";
	cout << "Ingrese el tiempo:  ";
	cin >> tiempo;

	altura = (gravedad * tiempo * tiempo)/2;


	cout << "La altura del edificio fue: " << altura <<endl;

	return 0;
}