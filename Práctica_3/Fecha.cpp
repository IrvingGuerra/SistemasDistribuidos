#include "Fecha.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa){}


void Fecha::inicializaFecha(int dd, int mm, int aaaa){

	if(dd > 31 || dd < 1){
		cout << "Valor ilegal para el dia!\n";
		exit(1);
	}else if(mm > 12 || mm < 1){
		cout << "Valor ilegal para el mes!\n";
		exit(1);
	}else if(aaaa > 2019 || aaaa < 0){
		cout << "Valor ilegal para el anio!\n";
		exit(1);
	}else{
		dia = dd;
		mes = mm;
		anio = aaaa;
	}

}
void Fecha::muestraFecha(){
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
	return;
}

int Fecha::convierte(){
	return anio*10000+mes*100+dia;
}

bool Fecha::leapyr(){
	if (anio % 400 == 0){
		return true;
	}else if (anio % 4 == 0 && anio % 100 != 0){
		return true;
	}else {
		return false;
	}
}
