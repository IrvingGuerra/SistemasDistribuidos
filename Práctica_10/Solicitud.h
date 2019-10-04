#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "SocketDatagrama.h"

class Solicitud{
	private:
		SocketDatagrama *socketlocal;
	public:
		Solicitud();
		char * doOperation(char *IP, int puerto, int operationId, char *arguments);
};
#endif