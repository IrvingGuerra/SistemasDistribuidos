#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <cmath>
#include <unistd.h>

using namespace std;

string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string getPalabra(){
	string palabra;
	for(int i = 0; i < 3; i++){
		int random = rand() % 26;
		palabra += letras[random];
	}
	return palabra;
}

int main(void){
	int const N = (int)pow(26, 3) * 100;
	int semilla = time(NULL);
	srand(semilla);
	string palabrota;
	for(int i = 0; i < N; i++){
		palabrota += (getPalabra() + " ");	
	}
	//cout << palabrota << endl;
	//cout << "El indice donde se encuentra la cadena IPN es: " << palabrota.find("IPN") << endl;
	//cout << palabrota[palabrota.find("IPN")] << palabrota[palabrota.find("IPN")+1] << palabrota[palabrota.find("IPN")+2] << endl;
	//cout << "la semilla fue :" << semilla << endl;
	int PrimeraPosicion = 0;
	int ocurrencias = 0;
	while(palabrota.find("IPN",PrimeraPosicion) < N*4){
		// cout << "El indice donde se encuentra la cadena IPN es: " << palabrota.find("IPN",PrimeraPosicion) << endl;
		// cout << palabrota[palabrota.find("IPN",PrimeraPosicion)] << palabrota[palabrota.find("IPN",PrimeraPosicion)+1] << palabrota[palabrota.find("IPN",PrimeraPosicion)+2] << endl;
		PrimeraPosicion = palabrota.find("IPN",PrimeraPosicion) + 3;
		ocurrencias++;
	}
	cout << "Ocurrencias: " << ocurrencias << endl;
	return 0;
}
