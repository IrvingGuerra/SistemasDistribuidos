#ifndef SOCKETMULTICAST_H
#define SOCKETMULTICAST_H

#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"


#define INTENTOS 3
#define UNICAST_PORT 7000

class SocketMulticast
{
private:
    int socketId;
    unsigned int ultimoId;

public:
    SocketMulticast(int puerto);
    ~SocketMulticast();
    int recibe(PaqueteDatagrama &pd);
    int recibeConfiable(PaqueteDatagrama &pd);
    int envia(PaqueteDatagrama &pd, unsigned char ttl);
    int enviaConfiable(PaqueteDatagrama &pd, unsigned char ttl, int totalReceptores);
    void unirAlGrupo(const char *direccionMulticast);
    void salirDelGrupo(const char *direccionMulticast);
    void fijarUltimoId(unsigned int id);
    unsigned int obtenerUltimoId();
};

#endif
