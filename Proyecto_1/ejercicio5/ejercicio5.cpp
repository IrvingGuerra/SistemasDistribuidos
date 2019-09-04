#include "Fraccion.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){

	cout << "Ejercicio 5 - Fracciones" << endl;

	//Imrpimimos el valor por defecto
	Fraccion a;

	cout << endl << "- Por defecto (1/2) -" << endl;

	cout << a.getNumerador() << " numerador" << endl;
	cout << a.getDenominador() << " denominador" << endl;
	cout << a.getFraccion() << " fraccion" << endl;
	cout << a.getMinimaExpresion()[0] << " / " << a.getMinimaExpresion()[1] << " Minima expresion" << endl;

	cout << endl << "- Seteamos (18/15) -" << endl;

	a.setNumerador(18);
	a.setDenominador(15);

	cout << a.getNumerador() << " numerador" << endl;
	cout << a.getDenominador() << " denominador" << endl;
	cout << a.getFraccion() << " fraccion" << endl;
	cout << a.getMinimaExpresion()[0] << " / " << a.getMinimaExpresion()[1] << " Minima expresion" << endl;

	return 0;
}