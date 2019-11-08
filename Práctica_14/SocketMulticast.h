#ifndef SOCKETMULTICAST_H
#define SOCKETMULTICAST_H

#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#include "PaqueteDatagrama.h"

class SocketMulticast
{
private:
    int socketId;
public:
    SocketMulticast(int puerto);
    ~SocketMulticast();
    int recibe(PaqueteDatagrama &pd);
    int envia(PaqueteDatagrama &pd, unsigned char ttl);
    int enviaConfiable(PaqueteDatagrama &pd, unsigned char ttl, int num_receptores);
    void unirAlGrupo(const char * direccionMulticast);
    void salirDelGrupo(const char * direccionMulticast);
};

#endif
