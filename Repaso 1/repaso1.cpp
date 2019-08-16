#include<stdlib.h> 
#include<stdio.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int main(void){

	char caracter = 0;
	int entero = 0; 
	float flotante = 0;
	long largo = 0;
	double doble = 0;

	printf("\n"BOLDRED"=================== Ejercicio 1 ==================="RESET"\n\n");


	printf("\t%p <--- Direccion Caracter\n", &caracter);
	printf("\t%p <--- Direccion Entero\n", &entero);
	printf("\t%p <--- Direccion Flotante\n", &flotante);
	printf("\t%p <--- Direccion Largo\n", &largo);
	printf("\t%p <--- Direccion Doble\n\n", &doble);

	printf("\t%lu <--- Tamaño Caracter\n", sizeof(caracter));
	printf("\t%lu <--- Tamaño Entero\n", sizeof(entero));
	printf("\t%lu <--- Tamaño Flotante\n", sizeof(flotante));
	printf("\t%lu <--- Tamaño Largo\n", sizeof(largo));
	printf("\t%lu <--- Tamaño Doble\n\n", sizeof(doble));

	printf("\t"BOLDBLUE"============ MAPA DE DIRECCIONES ============"RESET"\n\n\n\n\n\n\n\n");

	printf("\n"BOLDRED"=================== Ejercicio 2 ==================="RESET"\n\n");

	printf("¿Cuántos bits se almacenan en una dirección de memoria?"BOLDGREEN" 8 bits / 1 byte "RESET" \n\n");
	printf("¿Cuál es el máximo valor hexadecimal, decimal y binario que puede almacenarse en una dirección de memoria? "BOLDGREEN" 0xFF, 255, 11111111 "RESET"\n\n");
	printf("¿Las variables se encuentran almacenadas en el orden en que fueron declaradas? "BOLDGREEN" Windows NO, Linux SI "RESET"\n\n");
	printf("¿Las variables se almacenan en direcciones contiguas?  "BOLDGREEN" Windows NO, Linux SI "RESET"\n\n");
	printf("¿Los datos del tipo float, long y double ocupan la misma cantidad de bytes en todas las computadoras de su equipo? "BOLDGREEN" SI "RESET"\n\n");

	printf("\n"BOLDRED"=================== Ejercicio 3 ==================="RESET"\n\n");

	printf("¿Cuál sería la máxima dirección de memoria que se podría imprimir? "BOLDGREEN" 512MB En esta PC "RESET"\n\n");
	printf("¿Cuantos bytes sería posible almacenar en la RAM? "BOLDGREEN" 536,870,912 bytes // 512MB "RESET"\n\n");

	printf("\n"BOLDRED"=================== Ejercicio 4 ==================="RESET"\n\n");

	char *pcaracter;
	int *pentero;
	float *pflotante;
	long *plargo;
	double *pdoble; 

	printf("\t%lu <--- Tamaño pCaracter\n", sizeof(pcaracter));
	printf("\t%lu <--- Tamaño pEntero\n", sizeof(pentero));
	printf("\t%lu <--- Tamaño pFlotante\n", sizeof(pflotante));
	printf("\t%lu <--- Tamaño pLargo\n", sizeof(plargo));
	printf("\t%lu <--- Tamaño pDoble\n\n", sizeof(pdoble));

	printf("¿Cuántos bytes ocupa cada apuntador?  "BOLDGREEN" Ocupan lo mismo, dependiendo la arcquitectura, 4 para 32bits y 8 para 64bits "RESET"\n\n");

	printf("\t%lu <--- Contenido pCaracter (BASURA)\n", &pcaracter);
	printf("\t%lu <--- Contenido pEntero (BASURA)\n", &pentero);
	printf("\t%lu <--- Contenido pFlotante (BASURA)\n", &pflotante);
	printf("\t%lu <--- Contenido pLargo (BASURA)\n", &plargo);
	printf("\t%lu <--- Contenido pDoble (BASURA)\n\n", &pdoble);

	caracter = 'c';

	char *pcaracter2 = &caracter;

	printf("\tcaracter = 'c';\n");
	printf("\tchar *pcaracter2 = &caracter;\n\n");

	printf("\t%c <--- Apuntador pcaracter2 a direccion de caracter\n\n", *pcaracter2);

	printf("\n"BOLDRED"=================== Ejercicio 5 ==================="RESET"\n\n");

	char cadena[] = "ESCOM - IPN";

	printf("\t%s <--- Cadena\n\n", cadena);
	printf("\t%lu <--- Tamaño Cadena\n\n", sizeof(cadena));

	for (int i = 0; i < sizeof(cadena); ++i){
		printf("\t%p <--- Direccion letra %c\n", &cadena[i],cadena[i]);
	}

	printf("\n¿Son direcciones continuas o discontinuas? "BOLDGREEN" Continuas "RESET"\n\n");

	printf("\t%p <--- Direccion cadena+4 que contiene: %c (BASURA)\n", &cadena[sizeof(cadena)+4],cadena[sizeof(cadena)+4]);

	printf("\t%p <--- Direccion cadena+1 que contiene: %c\n", &cadena[sizeof(cadena)-1],cadena[sizeof(cadena)-1]);


	printf("\n"BOLDRED"=================== Ejercicio 6 ==================="RESET"\n\n");

	int variable = 1234567890;

	printf("\t%d <--- Contenido Decimal\n\n", variable);
	printf("\t%x <--- Contenido Hexadecimal\n\n", variable);

	printf("\n¿Corresponde el valor decimal con su equivalente en hexadecimal? "BOLDGREEN" SI "RESET"\n\n");

	variable = -1234567890;

	printf("\t%d <--- Contenido Decimal\n\n", variable);
	printf("\t%x <--- Contenido Hexadecimal\n\n", variable);
	
	for(int i = 0; i < 10; i++){
		printf("\n %d, %x || %d, %x\n", i, i, -i, -i);
	}
	
	printf("\nNo coincide en el caso de los numeros negativos ya que los números negativos usando un complemento a dos\n");
	printf("\n¿Cuál es el máximo valor negativo y positivo que puede almacenar un entero en su computadora? "BOLDGREEN" El máximo número que la una variable entera positiva y negativa puede almacenar es 2147483647 (31 bits en 1) y -2147483648 (complemento a 2 de 31 bits en 0) "RESET"\n\n");
	printf("\n\n\n\n\n");

	// int max = 0xFFFF;
	// while (max < max + 1) {
	// 	max++;
	// }
	// printf("Max: %d\n", max);
	// int min = 0xFFFF * -1;
	// while (min > min - 1) {
	// 	min--;
	// }
	// printf("Min: %d", min);
	return 0;
}




