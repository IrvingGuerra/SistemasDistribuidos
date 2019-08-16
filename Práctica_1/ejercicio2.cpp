#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */

const double PI = 3.1415926;

int main( ){
	int radio;

	cout << BOLDRED"\n=================== Ejercicio 2 ==================="RESET"\n";
	int entero1 = 8;
	int entero2 = 5;
	cout << "Entero 8/ Entero 5 = "<<entero1/entero2<<endl;
	int entero3 = 8;
	float float2 = 5;
	cout << "Entero 8/ Float 5 = "<<entero3/float2<<endl;
	return 0;
}