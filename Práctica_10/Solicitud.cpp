#include "Solicitud.h"
#include <iostream>

Solicitud::Solicitud(){
    int puertoLocal = 6000;
    socketlocal = new SocketDatagrama(puertoLocal);
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
    // Envía respuesta.
   // int mensaje[2] = {10, 5};
    int longitudMensaje =  5 * sizeof(int);
    PaqueteDatagrama saliente((char *)arguments, longitudMensaje, (char *)IP, puerto);
    int enviados = socketlocal->envia(saliente);
    std::cout << "Se enviaron " << enviados << "B" << std::endl;

    int * test = (int *)arguments;
    for (unsigned int i = 0; i < 5; i++)
    {
        std::cout << "        " << i << ":"  << test[i] << std::endl;
    }


    // Recibe datos.
    PaqueteDatagrama entrante(sizeof(int));
    int recibidos = socketlocal->recibe(entrante);
    std::cout << "Paquete recibido (" << recibidos << "B)" << std::endl;

    std::cout << "    Datos:" << std::endl;
    int * datos = (int *)entrante.obtieneDatos();
    for (unsigned int i = 0; i < entrante.obtieneLongitud() / sizeof(int); i++)
    {
        std::cout << "        " << i << ":"  << datos[i] << std::endl;
    }

    int *resultado = new int[1];

    resultado[0] = datos[0];

    return (char *)resultado;
}
