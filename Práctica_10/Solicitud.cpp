#include "Solicitud.h"

Solicitud::Solicitud(SocketDatagrama *socketlocal){
    int puertoLocal = 6000;
    SocketDatagrama sd(puertoLocal);
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
    // Envía respuesta.
   // int mensaje[2] = {10, 5};
    int longitudMensaje = 5 * sizeof(int);
    PaqueteDatagrama saliente(arguments, longitudMensaje, IP, puerto);
    int enviados = sd.envia(saliente);
    std::cout << "Se enviaron " << enviados << "B" << std::endl;

    // Recibe datos.
    PaqueteDatagrama entrante(2 * sizeof(int));
    char * recibidos = sd.recibe(entrante);

    std::cout << "Paquete recibido (" << recibidos << "B)" << std::endl;

    return  recibidos;
}
