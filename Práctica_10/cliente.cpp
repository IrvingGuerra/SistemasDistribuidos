#include "Solicitud.h"

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
    resultado = *(int *)solicitud.doOperation(argv[1], atoi(argv[2]), ADD, (char *)operandos, sizeof(operandos));
    std::cout << "Suma: " << resultado << std::endl;
    resultado = *(int *)solicitud.doOperation(argv[1], atoi(argv[2]), SUB, (char *)operandos, sizeof(operandos));
    std::cout << "Resta: " << resultado << std::endl;

    return 0;
}
