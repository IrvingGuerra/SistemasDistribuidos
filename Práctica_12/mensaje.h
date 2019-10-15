#ifndef MENSAJE_H
#define MENSAJE_H

// Tamaño máximo de bytes que se pueden mandar.
#define MAX_DATA_SIZE 16000 //16360

// Tipos de operaciones.
#define ADD 1 // Suma
#define SUB 2 // Resta
#define DEPOSITO 3

// Tipos de mensaje.
#define REQUEST 0
#define REPLY 1

// Definicion del formato de mensaje.
struct mensaje
{
	// 0: Solicitud, 1: Respuesta
	int messageType;

	// Identificador del mensaje
	unsigned int requestID;

	// Identificador de la operación
	int operationID;

	// Datos a ser mandados.
	char args[MAX_DATA_SIZE];

};

#endif