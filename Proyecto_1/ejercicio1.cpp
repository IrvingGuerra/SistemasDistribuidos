#include <iostream>
using namespace std;

int main( ){
	double x;
	double b;
	double h = 0;

	cout << "\n=================== Ejercicio 1 ===================\n";
	cout << "\n================= Raiz Babilonica ===================\n\n";
	cout << "Ingrese un numero:  ";
	cin >> x;

	b = x;

	while (b != h) {
        b = (h + b) / 2;
        h = x / b;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4); 

	cout << "La raiz del numero: " << x << " es: " << b <<endl;

	return 0;
}