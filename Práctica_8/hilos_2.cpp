#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;

int variable = 0;

void incrementa(int n)
{
    variable++;
    sleep(1);
}

void decrementa(int n)
{
    variable--;
    sleep(1);
}

int main()
{
    int n = 10;
    thread th1(incrementa, n), th2(decrementa, n);
    printf("Proceso principal espera que los hilos terminen.\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina.\n");
    printf("Valor final de la variable: %d\n", variable);
    exit(0);
}