#include <iostream>
using namespace std;

int main (void) {
    double precio = 78.7;
    cout << precio << endl;
    cout.setf(ios::fixed); // Forza cout a mostrar punto decimal
    cout.setf(ios::showpoint); // Muestra todos los digitos tal como se ingesaron en el programa.
    cout.precision(2); // Indica la cantidad de decimales después del punto a mostrar.
    cout << precio << endl;
    return 0;
}