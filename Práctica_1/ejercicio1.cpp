#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */

const double PI = 3.1415926;

int main( ){
	int radio;

	cout << BOLDRED"\n=================== Ejercicio 1 ==================="RESET"\n";
	cout << "Ingrese el radio del circulo:  ";
	cin >> radio;

	float res = PI*radio*radio;

	cout << "El area del circulo es: " << res <<endl<<endl;

	return 0;
}