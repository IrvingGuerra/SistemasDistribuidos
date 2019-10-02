#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "SocketDatagrama.h"

class Respuesta{
	public:
		Respuesta(int pl);
		struct mensaje *getRequest(void);
		void sendReply(char *respuesta);
	private:
		SocketDatagrama *socketlocal;
};

#endif