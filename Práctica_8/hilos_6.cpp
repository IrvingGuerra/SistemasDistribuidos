#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>

using namespace std;

int variable = 0;

mutex m;

void incrementa(int n)
{
    m.lock();
    for (register int i = 0; i < n; i++)
    {
        variable++;
    }
    m.unlock();
}

void decrementa(int n)
{
    m.lock();
    for (register int i = 0; i < n; i++)
    {
        variable--;
    }
    m.unlock();
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