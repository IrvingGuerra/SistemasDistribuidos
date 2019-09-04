#include "Temperatura.h"
#include <iostream>
#include <string.h>
using namespace std;

Temperatura::Temperatura(double grados) : kelvin(grados){} 

void Temperatura::setTempKelvin(double grados){
	kelvin = grados; //No se hace conversion, ya que se guarda siempre en kelvin
}

void Temperatura::setTempFahrenheit(double grados){
	//Conversion de Fahrenheit a Kelvin
	kelvin = (grados + 459.67) * 5/9;
}

void Temperatura::setTempCelsius(double grados){
	//Conversion de Fahrenheit a Kelvin
	kelvin = grados + 273.15;
}
 
double Temperatura::getTemp(char type){
	double resultado = 0;
	switch(type){
		case 'k':
			//La pide en Kelvin
			resultado = kelvin;
		break;
		case 'f':
			//La pide en Fahrenheit
			resultado = (kelvin * 9/5) - 459.67;
		break;
		case 'c':
			//La pide en Celsius
			resultado = (kelvin - 273.15);
		break;
	}
	return resultado;
}
