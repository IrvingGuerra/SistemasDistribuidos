#include "Fecha.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    Fecha a, b, c(21, 9, 1973);
    b.inicializaFecha(17, 6 , 2000); 
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();
    cout << a.leapYr() << endl;
    cout << b.leapYr() << endl;
    cout << c.leapYr() << endl;
    cout << a.convierte() << endl;
    cout << b.convierte() << endl;
    cout << c.convierte() << endl;
    Fecha lp;
    int lpyrs = 0;
    for (int i = 1; i <= 2019; i++) {
        lp.inicializaFecha(1, 1, i);
        if (lp.leapYr()) {
            lpyrs++;
        }
    }
    cout << "Años bisietos: " << lpyrs << endl;
    return 0;
}
