#include "Fecha.h"
#include <iostream>
using namespace std;

int main(){
	Fecha a;
	int cuenta = 0;

	for (int i = 0; i < 2020; ++i){
		a.inicializaFecha(17, 6 , i);
		if (a.leapyr() == 1){
			cout << i << "Es viciesto" << endl;
			cuenta++;
		}
	}
	cout << "Hay: " << cuenta << " años biciestos";
} 