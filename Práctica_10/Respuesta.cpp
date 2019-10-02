#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "Respuesta.h"
#include "mensaje.h"

Respuesta::Respuesta(int pl){ //recibe puerto
	SocketDatagrama sd(pl);
}


mensaje *Respuesta::getRequest(){

	

}

void Respuesta::sendReply(char *respuesta){

}
