#include "Solicitud.h"
#include <iostream>

Solicitud::Solicitud()
{
    socketlocal = new SocketDatagrama(0);
}


char *Solicitud::doOperation(const char *serverIpAdress, int serverPort, int operationID, char *args, unsigned int argsLen)
{

    // Genera un mensaje para enviar los argumentos.
    mensaje _request;
    unsigned int requestID = rand();
    // Se encapsula el tipo de mensaje, un identificador aleatorio y la operación a realizar.
    _request = {REQUEST, requestID, operationID};
    // Se copian los argumentos de la operación a la estructura.
    mempcpy(_request.args, args, argsLen);

    // Genera y envía paquete de datagrama.
    PaqueteDatagrama saliente((char *)&_request, sizeof(_request), serverIpAdress, serverPort);

    // Se recibe un mensaje
    PaqueteDatagrama entrante(MAX_DATA_SIZE + 12);
    register int i = 0;
    for (i = 0; i < 7; i++) {
        socketlocal->envia(saliente);
        if (socketlocal->recibeTimeout(entrante, 1, 0) != -1) {
            break;
        }
    }
    if (i == 7) {
        perror("El servidor no está dsponible. Intente más tarde.");
        exit(EXIT_FAILURE);
    }
    mensaje *_reply = new mensaje[1];
    memcpy(_reply, entrante.obtieneDatos(), sizeof(mensaje));

    // Se valida.
    if (_reply->requestID != requestID)
    {
        char error[100];
        sprintf(error, "ID de petición incorrecto. Se esperaba %u y se obtuvo %u",
                requestID,
                _reply->requestID);
        perror(error);
        exit(EXIT_FAILURE);
    }

    if (_reply->operationID != operationID)
    {
        char error[100];
        sprintf(error, "ID de operación incorrecto. Se esperaba %d y se obtuvo %d",
                operationID,
                _reply->operationID);
        perror(error);
        exit(EXIT_FAILURE);
    }


    if (_reply->messageType != REPLY)
    {
        perror("Mensaje recibido no es una respuesta.");
        exit(EXIT_FAILURE);
    }

    // Se retorna el resultado de la operación enviada al servidor.
    return _reply->args;

}
