#include <iostream>
using namespace std;

const double gravedad = 9.8;

int main( ){
	int segundos,horas,minutos;

	cout << "\n=================== Ejercicio 3 ===================\n";
	cout << "\n================= Segundos a H,M,S===================\n\n";
	cout << "Ingrese el tiempo en segundos:  ";
	cin >> segundos;

	horas = segundos / 3600;
	segundos = segundos - (3600*horas);
	minutos = segundos / 60;
	segundos = segundos - (60*minutos);

	cout << "El tiempo es de: " << horas << "horas, " << minutos << "minutos y " << segundos << " segundos" <<endl;

	return 0;
}