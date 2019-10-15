#include "SocketDatagrama.h"

SocketDatagrama::SocketDatagrama(int puertoLocal)
{
    s = socket(AF_INET, SOCK_DGRAM, 0);

    int longitudLocal = sizeof(direccionLocal);

    bzero(&direccionLocal, longitudLocal);
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(puertoLocal);

    bind(s, (sockaddr *)&direccionLocal, longitudLocal);
}

int SocketDatagrama::envia(PaqueteDatagrama &p)
{
    int longitudForanea = sizeof(direccionForanea);

    bzero((char *)&direccionForanea, longitudForanea);
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());

    return sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, longitudForanea);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p)
{
    // Recibe datos.
    int longitudForanea = sizeof(direccionForanea);
    int recibidos = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t *)&longitudForanea);

    // Guarda direccción fuente.
    uint32_t direccionFuente = ntohl(direccionForanea.sin_addr.s_addr);
    char direccionFuenteCadena[16];
    sprintf(direccionFuenteCadena, "%u.%u.%u.%u",
            direccionFuente >> 24 & 0xff,
            direccionFuente >> 16 & 0xff,
            direccionFuente >> 8 & 0xff,
            direccionFuente & 0xff);
    p.inicializaIp(direccionFuenteCadena);

    // Guarda puerto fuente.
    in_port_t puertoFuente = ntohs(direccionForanea.sin_port);
    p.inicializaPuerto(puertoFuente);

    return recibidos;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos)
{
    timeout.tv_sec = segundos;
    timeout.tv_usec = microsegundos;
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    //---------------
    // Recibe datos.
    int longitudForanea = sizeof(direccionForanea);
    int recibidos = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t *)&longitudForanea);

    // Guarda direccción fuente.
    uint32_t direccionFuente = ntohl(direccionForanea.sin_addr.s_addr);
    char direccionFuenteCadena[16];
    sprintf(direccionFuenteCadena, "%u.%u.%u.%u",
            direccionFuente >> 24 & 0xff,
            direccionFuente >> 16 & 0xff,
            direccionFuente >> 8 & 0xff,
            direccionFuente & 0xff);
    p.inicializaIp(direccionFuenteCadena);

    // Guarda puerto fuente.
    in_port_t puertoFuente = ntohs(direccionForanea.sin_port);
    p.inicializaPuerto(puertoFuente);
    //--------------
    if (recibidos < 0)
    {
        if (errno == EWOULDBLOCK)
        {
            fprintf(stderr, "Tiempo de recepción transcurrido\n");
        }
        else
        {
            fprintf(stderr, "Error en recvfrom\n");
        }
    }
    return recibidos;
}

SocketDatagrama::~SocketDatagrama()
{
    close(s);
}