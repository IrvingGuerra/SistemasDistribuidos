#include "Solicitud.h"
#define N 100000
#include <iostream>

int main(int argc, char const *argv[])
{

    if (argc != 3)
    {
        printf("Forma de ejecutar: ./%s [SERVER IP ADDRESS] [SERVER PORT]\n", argv[0]);
        exit(0);
    }

    // Obtención de operandos.
    int operandos[2];
    std::cout << "Ingrese operandos separados por espacio: ";
    std::cin >> operandos[0] >> operandos[1];

    // Solicitud.
    Solicitud solicitud;
    int resultado;

    // Resultados.
    for (int i = 0; i < N; i++)
    {
        resultado = *(int *)solicitud.doOperation(argv[1], atoi(argv[2]), ADD, (char *)operandos, sizeof(operandos));
        std::cout << "Suma: " << resultado << std::endl;
    }

    return 0;
}
