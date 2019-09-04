#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> variable(0);

void incrementa(int n)
{
    for (register int i = 0; i < n; i++)
    {
        variable++;
    }
}

void decrementa(int n)
{
    for (register int i = 0; i < n; i++)
    {
        variable--;
    }
}

int main()
{
    int n = 1000;
    thread th1(incrementa, n), th2(decrementa, n);
    printf("Proceso principal espera que los hilos terminen.\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina.\n");
    cout << "Valor final de la variable: " << variable << endl;
    exit(0);
}