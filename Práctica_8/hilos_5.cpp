#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>

#define N 1000

using namespace std;

void incrementa(atomic<int> & variable)
{
    for (register int i = 0; i < N; i++)
    {
        variable++;
    }
}

void decrementa(atomic<int> & variable)
{
    for (register int i = 0; i < N; i++)
    {
        variable--;
    }
}

int main()
{
    atomic<int> variable(0);
    thread th1(incrementa, ref(variable)), th2(decrementa, ref(variable));
    printf("Proceso principal espera que los hilos terminen.\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina.\n");
    cout << "Valor final de la variable: " << variable << endl;
    exit(0);
}