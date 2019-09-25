#include "PaqueteDatagrama.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa){}


void PaqueteDatagrama::PaqueteDatagrama(char *data, unsigned int longitud, char *ip, int puerto){

}

void PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud){

}

void PaqueteDatagrama::~PaqueteDatagrama(){

}

char *PaqueteDatagrama::obtieneDireccion(){
	return *ip;
}
unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}
int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}
char *PaqueteDatagrama::obtieneDatos(){
	return *datos;
}
void PaqueteDatagrama::inicializaPuerto(int pto){
	puerto = pto;
}
void PaqueteDatagrama::inicializaIp(char *ipadd){
	*ip = *ipadd;
}
void PaqueteDatagrama::inicializaDatos(char *data){
	*datos = *data;
}