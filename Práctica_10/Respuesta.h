#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "mensaje.h"
#include "SocketDatagrama.h"

class Respuesta{
	private:
		SocketDatagrama *socketlocal;
	public:
		Respuesta(int pl);
		struct mensaje *getRequest(void);
		void sendReply(char *respuesta);
};

#endif