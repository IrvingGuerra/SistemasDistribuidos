#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "mensaje.h"

class Respuesta
{
private:
public:
	// Bandera que indica si la petición fue enviada de nuevo.
	bool newRequest = false;
	
	// Socket para enviarobtieneDireccion respuestas y recibir peticiones.
	SocketDatagrama *socketLocal;

	// Dirección de cliente que hizo la solicitud.
	char clientIpAddress[16];

	// Puerto de cliente que hizo la solicitud.
	int clientPort;

	// ID de solicitud.
	unsigned int requestID;

	// ID de operación.
	int operationID;

	// Constructor de un objeto que envía respuestas.
	Respuesta(int port);

	// Obtiene una respuesta de algún cliente.
	mensaje *getRequest();

	// Envía respuestas.
	void sendReply(char *reply, unsigned int replyLen);
};

#endif