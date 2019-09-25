#include "DatagramSocket.h"

DatagramSocket::DatagramSocket(int port)
{
    socketId = socket(AF_INET, SOCK_DGRAM, 0);

    /* rellena la dirección del servidor */
    bzero((char *)&foreignAddress, sizeof(foreignAddress));
    foreignAddress.sin_family = AF_INET;
    foreignAddress.sin_addr.s_addr = inet_addr("10.100.74.168");
    foreignAddress.sin_port = htons(7200);

    /* rellena la direcciòn del cliente*/
    bzero((char *)&localAddress, sizeof(localAddress));
    localAddress.sin_family = AF_INET;
    localAddress.sin_addr.s_addr = INADDR_ANY;

    /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
    localAddress.sin_port = htons(port);
    bind(socketId, (struct sockaddr *)&localAddress, sizeof(localAddress));
}

DatagramSocket::~DatagramSocket()
{
    close(socketId);
}

//Recibe un paquete tipo datagrama proveniente de este socket
int DatagramSocket::receive(PaqueteDatagrama &p)
{
    // Recibe y guarda datos.
    char *datos;
    int recibidos = recvfrom(socketId, datos, p.obtieneLongitud(), 0, NULL, NULL);
    p.inicializaDatos(datos);

    // Adapta dirección a string y guarda.
    char *ip;
    uint32_t s_addr_client = localAddress.sin_addr.s_addr;
    s_addr_client = ntohl(s_addr_client);
    sprintf(ip, "%d.%d.%d.%d",
            s_addr_client >> 24 & 0xff,
            s_addr_client >> 16 & 0xff,
            s_addr_client >> 8 & 0xff,
            s_addr_client & 0xff);
    p.inicializaIp(ip);
    // Adapta puerto y guarda.
    in_port_t s_port_client = localAddress.sin_port;
    s_port_client = ntohs(s_port_client);
    p.inicializaPuerto(s_port_client);

    return recibidos;
}

//Envía un paquete tipo datagrama desde este socket
int DatagramSocket::send(PaqueteDatagrama &p)
{
    return sendto(socketId, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&foreignAddress, sizeof(foreignAddress));
}