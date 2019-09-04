#include "Temperatura.h"
#include <iostream>
#include <string.h>
using namespace std;

Temperatura::Temperatura(double grados) : kelvin(grados){} 

void Temperatura::setTempKelvin(double grados){
	kelvin = grados;
}
 
double Temperatura::getTemp(char type){
	switch(type){
		case 'k':
			return kelvin;
		break;
		case 'f':
		break;
		case 'c':
		break;
	}
}
