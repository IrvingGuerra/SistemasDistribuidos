#include "Fraccion.h"
#include <iostream>
#include <algorithm>
using namespace std;

Fraccion::Fraccion(int num,int den) : numerador(num),denominador(den){} 

void Fraccion::setNumerador(int num){
	numerador = num;
}

void Fraccion::setDenominador(int den){
	denominador = den;
}
 
int Fraccion::getNumerador(){
	return numerador;
}

int Fraccion::getDenominador(){
	return denominador;
}
 
double Fraccion::getFraccion(){
	return (double)numerador/denominador;
}

int * Fraccion::getMinimaExpresion( ) {

	static int  res[2];

	int a = 0, b = 0, mcd = 0;

    a = std::max(numerador,denominador);
    b = std::min(numerador,denominador);

    do{
		mcd = b;
        b = a%b;
        a = mcd;
    } while (b!=0);
	
	res[0] = numerador / mcd;
	res[1] = denominador / mcd;

	return res;
}



