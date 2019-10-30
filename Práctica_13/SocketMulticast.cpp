#include "SocketMulticast.h"

SocketMulticast::SocketMulticast(int puerto)
{
    socketId = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    int len = sizeof(direccion);
    bzero(&direccion, len);
    direccion.sin_family = AF_INET;
    direccion.sin_addr.s_addr = INADDR_ANY;
    direccion.sin_port = htons(puerto);

    bind(socketId, (sockaddr *)&direccion, len);
}

SocketMulticast::~SocketMulticast()
{
    close(socketId);
}

int SocketMulticast::recibe(PaqueteDatagrama &pd)
{
    // Recibe datos.
    sockaddr_in direccionForanea;
    int longitudForanea = sizeof(direccionForanea);
    int recibidos = recvfrom(socketId,
                             pd.obtieneDatos(),
                             pd.obtieneLongitud(),
                             0,
                             (struct sockaddr *)&direccionForanea,
                             (socklen_t *)&longitudForanea);

    // Guarda direccción fuente.
    uint32_t direccionFuente = ntohl(direccionForanea.sin_addr.s_addr);
    char direccionFuenteCadena[16];
    sprintf(direccionFuenteCadena, "%u.%u.%u.%u",
            direccionFuente >> 24 & 0xff,
            direccionFuente >> 16 & 0xff,
            direccionFuente >> 8 & 0xff,
            direccionFuente & 0xff);
    pd.inicializaIp(direccionFuenteCadena);

    // Guarda puerto fuente.
    in_port_t puertoFuente = ntohs(direccionForanea.sin_port);
    pd.inicializaPuerto(puertoFuente);

    return recibidos;
}

int SocketMulticast::envia(PaqueteDatagrama &pd, unsigned char ttl)
{
    unsigned char TTL = ttl;
    setsockopt(socketId, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&TTL, sizeof(TTL));
    return sendto(socketId, pd.obtieneDatos(), pd.obtieneLongitud(), 0, (sockaddr *)&direccion, sizeof(direccion));
}

void SocketMulticast::unirAlGrupo(const char *direccionMulticast)
{
    direccion.sin_addr.s_addr = inet_addr(direccionMulticast);
    ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(direccionMulticast);
    multicast.imr_interface.s_addr = INADDR_ANY;
    setsockopt(socketId, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&multicast, sizeof(multicast));
}

void SocketMulticast::salirDelGrupo(const char *direccionMulticast)
{
    ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(direccionMulticast);
    multicast.imr_interface.s_addr = INADDR_ANY;
    setsockopt(socketId, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *)&multicast, sizeof(multicast));
}