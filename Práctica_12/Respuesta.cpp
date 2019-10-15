#include "Respuesta.h"

Respuesta::Respuesta(int port)
{
    // Recibe puerto por el que se compunica el servidor.
    socketLocal = new SocketDatagrama(port);
}

mensaje *Respuesta::getRequest()
{
    // Recibe respuesta.
    PaqueteDatagrama request(MAX_DATA_SIZE + 12);
    socketLocal->recibe(request);
    mensaje *m = new mensaje[1];
    memcpy(m, request.obtieneDatos(), sizeof(mensaje));
    // Guarda datos de la petición para mandar la respuesta.
    strcpy(clientIpAddress, request.obtieneDireccion());
    clientPort = request.obtienePuerto();
    newRequest = requestID != m->requestID;
    requestID = m->requestID;
    operationID = m->operationID;
    return m;
}

/**
 * Se manda un mensaje de respuesta por parte del servidor
 * Se asume que la respuesta es un arreglo;;
 */
void Respuesta::sendReply(char *reply, unsigned int replyLen)
{
    // Genera un mensaje para enviar la respuesta.
    mensaje _reply = {REPLY, requestID, operationID};
    mempcpy(_reply.args, reply, replyLen);

    // Genera paquete.
    PaqueteDatagrama saliente((char *)&_reply, sizeof(_reply), clientIpAddress, clientPort);

    // Envía paquete.
    socketLocal->envia(saliente);
}
