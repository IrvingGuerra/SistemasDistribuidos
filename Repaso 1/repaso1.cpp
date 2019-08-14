#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){

	char caracter = 0;
	int entero = 0;
	float flotante = 0;
	long largo = 0;
	double doble = 0;



	printf("0x%p\n", &caracter);
	printf("0x%p\n", &entero);
	printf("0x%p\n", &flotante);
	printf("0x%p\n", &largo);
	printf("0x%p\n", &doble);

	printf("%d\n", sizeof(caracter));
	printf("%d\n", sizeof(entero));
	printf("%d\n", sizeof(flotante));
	printf("%d\n", sizeof(largo));
	printf("%d\n", sizeof(doble));



	return 0;
}


//CUantos bits se almacenan en una direccion de mmoria? 8 bits / 1 byte
//0xFF, 255, 11111111
//WIndows NO, LInux SI
//Windows NO, Linux SI
//Si


//512MB En esta PC
//536,870,912 bytes // 512MB


//4.- Ocupan lo mismo, dependiendo la arcquitectura, en este caso 4 para 32 y 8 para 64

//

