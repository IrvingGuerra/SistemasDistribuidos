#include "Solicitud.h"

Solicitud::Solicitud(){
    int puertoLocal = 6000;
    socketlocal = new SocketDatagrama(puertoLocal);
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
    // Envía respuesta.
   // int mensaje[2] = {10, 5};
    int longitudMensaje = 5 * sizeof(int);
    PaqueteDatagrama saliente(arguments, longitudMensaje, IP, puerto);
    int enviados = socketlocal->envia(saliente);

    // Recibe datos.
    PaqueteDatagrama entrante(sizeof(char));
    int recibidos = socketlocal->recibe(entrante);

    return (char *)entrante.obtieneDatos();
}
