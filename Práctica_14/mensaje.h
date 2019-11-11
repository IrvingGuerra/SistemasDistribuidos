#ifndef MENSAJE_H
#define MENSAJE_H

#include "SocketDatagrama.h"

// Tamaño máximo de bytes que se pueden mandar.
#define MAX_LONGITUD_MSG 16000 //16360

// Tipos de mensaje.
#define TRANSMIT false
#define REPLY true

// Definicion del formato de mensaje.
struct mensaje
{
	// 0: transmición, 1: respuesta.
	bool sentido;

	// Identificador del mensaje
	unsigned int id;

	// Datos a ser mandados.
	char args[MAX_LONGITUD_MSG];

};

#endif