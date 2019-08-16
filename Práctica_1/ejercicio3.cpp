#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
	double c, f;
	cout << "ingrese los grados centigrados a convertir" << endl;
	cin >> c;
	f = (static_cast<double>(9)/5) * c + 32.0;
	cout << "el  equivalente en grados fahrenheit es:" << f << endl;
	return 0;
}
