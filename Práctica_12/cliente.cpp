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
    // int operandos[2] = {0, 0};
    // std::cout << "Ingrese operandos separados por espacio: ";
    // std::cin >> operandos[0] >> operandos[1];


    // Solicitud.
    Solicitud solicitud;
    int resultado;

    // Resultados.
    int reqs = atoi(argv[3]);
    register int i = 0;
    int valorEsperado = 0;
    for (i = 0; i < reqs; i++)
    {
        int valorDeposito = rand() % 8 + 1;
        resultado = *(int *)solicitud.doOperation(argv[1], atoi(argv[2]), DEPOSITO, (char *)&valorDeposito, sizeof(valorDeposito));
        valorEsperado += valorDeposito;
        if (valorEsperado == resultado) {
            printf("Depósito de $%d realizado. Ahora se tiene $%d en la cuenta.\n", valorDeposito, resultado);
        } else {
            printf("Fallo en depósito %d de $%d. Se esperaban $%d y se obtuvieron $%d\n", i, valorDeposito,  valorEsperado, resultado);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
