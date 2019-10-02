#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "respuesta.h"
#include "mensaje.h"

respuesta::Respuesta(int pl){ //recibe puerto
	SocketDatagrama sd(pl);
}


mensaje respuesta::getRequest(){

	

}

respuesta::sendReply(char *respuesta){

}
