#ifndef SOCKETDATAGRAMA_H
#define SOCKETDATAGRAMA_H

#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>

#include "PaqueteDatagrama.h"

class SocketDatagrama
{
public:
    SocketDatagrama(int puertoLocal);
    ~SocketDatagrama();
    //Recibe un paquete tipo datagrama proveniente de este socket
    int recibe(PaqueteDatagrama &p);
    //Envía un paquete tipo datagrama desde este socket
    int envia(PaqueteDatagrama &p);

private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s; //ID socket
};

#endif