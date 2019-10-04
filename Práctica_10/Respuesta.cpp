#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "Respuesta.h"
#include "mensaje.h"

Respuesta::Respuesta(int pl){ //recibe puerto
	SocketDatagrama sd(pl);
}

mensaje *Respuesta::getRequest(){

	// Recibe datos.
	PaqueteDatagrama entrante(5 * sizeof(int));
    int recibidos = sd.recibe(entrante);

    // Log de datos recibidos.
   	int * datos = (int *)entrante.obtieneDatos();
   	dirFuente = entrante.obtieneDireccion();
    puertoFuente = entrante.obtienePuerto();

    mensaje request;

    request.messageType = datos[0];
    request.requestId = datos[1];
    request.operationId = datos[2];
    request.arguments[0] = datos[3];
    request.arguments[1] = datos[4];

    return request;
}

void Respuesta::sendReply(char *respuesta){
	 // Envía respuesta.
    int longitudRespuesta = sizeof(char);
    PaqueteDatagrama saliente((char *)respuesta, longitudRespuesta, dirFuente, puertoFuente);
    int enviados = sd.envia(saliente);
    std::cout << "Se enviaron " << enviados << "B" << std::endl;
}
