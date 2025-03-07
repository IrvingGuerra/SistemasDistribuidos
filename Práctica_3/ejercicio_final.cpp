#include <unistd.h>
#include <iostream>
using namespace std;
class NumerosRand
{
private:
    int *arreglo;
    unsigned int numeroElementos;

public:
    NumerosRand(unsigned int num);
    void inicializaNumerosRand(void);
};
NumerosRand::NumerosRand(unsigned int num)
{
    numeroElementos = num;
    arreglo = new int[numeroElementos];
}
void NumerosRand::inicializaNumerosRand()
{
    unsigned int i;
    for (i = 0; i < numeroElementos; i++)
        arreglo[i] = rand();
    cout << "Arreglo inicializado. Borrando números" << endl;
    sleep(3);
    delete arreglo;
    return;
}
void pruebaClase()
{
    unsigned int capacidad;
    cout << "Numero de enteros aleatorios en el arreglo : ";
    cin >> capacidad;
    NumerosRand tmp(capacidad);
    tmp.inicializaNumerosRand();
}
int main()
{
    char res;
    do
    {
        pruebaClase();
        cout << "Probar de nuevo? (s/n) ";
        cin >> res;
    } while ((res == 's') || (res == 'S'));
}