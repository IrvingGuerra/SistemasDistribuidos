#include "Solicitud.h"
#include <iostream>

int main(int argc, char const *argv[])
{

    if (argc != 4)
    {
        printf("Forma de ejecutar: ./%s [SERVER IP ADDRESS] [SERVER PORT] [REQUESTS]\n", argv[0]);
        exit(0);
    }

    // Obtención de operandos.
    int operandos[2] = {0, 0};
    // std::cout << "Ingrese operandos separados por espacio: ";
    // std::cin >> operandos[0] >> operandos[1];


    // Solicitud.
    Solicitud solicitud;
    int resultado;

    // Resultados.
    int reqs = atoi(argv[3]);
    register int i = 0;
    for (i = 0; i < reqs; i++)
    {
        //operandos[0] = i;
        resultado = *(int *)solicitud.doOperation(argv[1], atoi(argv[2]), ADD, (char *)operandos, sizeof(operandos));
        // if (i % 100 == 0)
        //     std::cout << i << std::endl;
    }

    return 0;
}
