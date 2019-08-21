#include "Fecha.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


int masViejaValor(Fecha fecha1, Fecha fecha2);
int masViejaReferencia(Fecha &fecha1, Fecha& fecha2);

int main(int argc, char* argv[]){
	Fecha a,b;
	int mes,dia,anio;
	a.inicializaFecha(21, 8 , 2018);
	b.inicializaFecha(21, 8 , 2019);

	if (atoi(argv[1]) == 0){
		for (int i = 0; i < 999999; ++i){
			mes = rand() % 12 + 1;
			dia = rand() % 31 + 1;
			anio = rand() % 2019 + 1;
			a.inicializaFecha(dia, mes, anio);
			mes = rand() % 12 + 1;
			dia = rand() % 31 + 1;
			anio = rand() % 2019 + 1;
			b.inicializaFecha(dia, mes, anio);
			masViejaValor(a,b);
		}
	}else if (atoi(argv[1]) == 1){
		for (int i = 0; i < 999999; ++i){
			mes = rand() % 12 + 1;
			dia = rand() % 31 + 1;
			anio = rand() % 2019 + 1;
			a.inicializaFecha(dia, mes, anio);
			mes = rand() % 12 + 1;
			dia = rand() % 31 + 1;
			anio = rand() % 2019 + 1;
			b.inicializaFecha(dia, mes, anio);
			masViejaReferencia(a,b);
		}
	}
}



int masViejaValor(Fecha fecha1, Fecha fecha2){

	if (fecha1.convierte() > fecha2.convierte()){
		return 1;
	}else if (fecha1.convierte() == fecha2.convierte()){
		return 0;
	}else if (fecha1.convierte() < fecha2.convierte()){
		return -1;
	}
}


int masViejaReferencia(Fecha &fecha1, Fecha &fecha2){

	if (fecha1.convierte() > fecha2.convierte()){
		return 1;
	}else if (fecha1.convierte() == fecha2.convierte()){
		return 0;
	}else if (fecha1.convierte() < fecha2.convierte()){
		return -1;
	}
}
