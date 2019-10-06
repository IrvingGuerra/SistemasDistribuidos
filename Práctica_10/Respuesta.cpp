#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "Respuesta.h"
#include "mensaje.h"
#include <iostream>

Respuesta::Respuesta(int pl){ //recibe puerto
	socketlocal = new SocketDatagrama(pl);
}

mensaje *Respuesta::getRequest(){

	// Recibe datos.
	PaqueteDatagrama entrante(5 * sizeof(int));
    int recibidos = socketlocal->recibe(entrante);

    // Log de datos recibidos.
    dirFuente = entrante.obtieneDireccion();
    puertoFuente = entrante.obtienePuerto();
    std::cout << "    Paquete recibido (" << recibidos << "B)" << std::endl;
    std::cout << "    Dirección fuente:" << dirFuente << std::endl;
    std::cout << "    Puerto fuente:" << puertoFuente << std::endl;
    std::cout << "    Longitud:" << entrante.obtieneLongitud() << std::endl;
    std::cout << "    Datos:" << std::endl;
    int * datos = (int *)entrante.obtieneDatos();
    for (unsigned int i = 0; i < entrante.obtieneLongitud() / sizeof(int); i++)
    {
        std::cout << "        " << i << ":"  << datos[i] << std::endl;
    }

    mensaje *request = (mensaje*)malloc(sizeof(mensaje));

    request->messageType = datos[0];
    request->requestId = datos[1];
    request->operationId = datos[2];
    request->arguments[0] = (char)datos[3];
    request->arguments[1] = (char)datos[4];

    return request;
}

void Respuesta::sendReply(char *respuesta){
	 // Envía respuesta.
    int longitudRespuesta = sizeof(int);
    PaqueteDatagrama saliente((char *)respuesta, longitudRespuesta, "192.168.0.2", 6000);
    int enviados = socketlocal->envia(saliente);
    std::cout << "Se enviaron " << enviados << "B" << std::endl;
}








