#include "Temperatura.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(){
	cout << "Ejercicio 4 - Temperaturas" << endl;

	//Imrpimimos el valor por defecto
	Temperatura a;

	cout << endl << "- Por defecto -" << endl;

	cout << a.getTemp('k') << " grados Kelvin" << endl;

	//Probamos cada metodo
	cout << endl << "- setTempKelvin 298.15 -" << endl;
	a.setTempKelvin(298.15);
	cout << a.getTemp('k') << " grados Kelvin" << endl;
	cout << a.getTemp('f') << " grados Fahrenheit" << endl;
	cout << a.getTemp('c') << " grados Celcius" << endl;

	cout << endl << "- setTempFahrenheit 77 -" << endl;
	a.setTempFahrenheit(77);
	cout << a.getTemp('k') << " grados Kelvin" << endl;
	cout << a.getTemp('f') << " grados Fahrenheit" << endl;
	cout << a.getTemp('c') << " grados Celcius" << endl;

	cout << endl << "- setTempCelcius 25 -" << endl;
	a.setTempCelsius(25);
	cout << a.getTemp('k') << " grados Kelvin" << endl;
	cout << a.getTemp('f') << " grados Fahrenheit" << endl;
	cout << a.getTemp('c') << " grados Celcius" << endl;
	

	return 0;
}
