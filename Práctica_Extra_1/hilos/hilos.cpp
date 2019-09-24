#include <iostream>
#include <sys/types.h>
#include <unistd.h>

#include <thread>

#include "funciones.h"

using namespace std;


int main(int argc, char *argv[])
{
    srand(getpid());

    if (argc != 2)
    {
        cout << "Forma de uso: " << argv[0] << " [1-7]" << endl;
        exit(0);
    }

    switch (atoi(argv[1]))
    {
    case 1:
    {
        thread t1(dd, 0);
        thread t2(dd, 1);
        t1.join();
        t2.join();
        break;
    }
    case 2:
    {
        thread t1(ram);
        thread t2(ram);
        t1.join();
        t2.join();
        break;
    }
    case 3:
    {
        thread t1(cpu);
        thread t2(cpu);
        t1.join();
        t2.join();
        break;
    }
    case 4:
    {
        thread t1(dd, 0);
        thread t2(cpu);
        t1.join();
        t2.join();
        break;
    }
    case 5:
    {
        thread t1(dd, 0);
        thread t2(ram);
        t1.join();
        t2.join();
        break;
    }
    case 6:
    {
        thread t1(cpu);
        thread t2(ram);
        t1.join();
        t2.join();
        break;
    }
    case 7:
    {
        thread t1(cpu);
        thread t2(dd, 0);
        thread t3(ram);
        t1.join();
        t2.join();
        t3.join();
        break;
    }
    case 8:
    {
        dd(0);
        break;
    }
    case 9:
    {
        ram();
        break;
    }
    case 10:
    {
        cpu();
        break;
    }

    default:
        cout << "Operación no válida." << endl;
        break;
    }
}
