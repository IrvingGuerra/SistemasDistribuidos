#include "SocketMulticast.h"

SocketMulticast::SocketMulticast(int puerto)
{
    ultimoId = -1;
    socketId = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    int reuse = 1;
    if (setsockopt(socketId, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1)
    {
        printf("Error al llamar a la función setsockopt\n");
        exit(0);
    }

    sockaddr_in direccion;
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

/**
 * Recibe un paquete de datagrama por multicast.
 * 
 * Retorna el número de bytes recibidos o -1 en caso de error.
 * 
 * El contenido del paquete debe ser una estructura tipo mensaje.
 * Si el mensaje recibido ya ha sido recibido, retorna -2.
 */
int SocketMulticast::recibeConfiable(PaqueteDatagrama &pd)
{
    // Se abre socket unicast para enviar respuesta.
    SocketDatagrama socketUnicast(0);

    // Recibe el paquete.
    int recibidos = recibe(pd);

    // Se extrae id.
    mensaje m = *(mensaje *)pd.obtieneDatos();

    if (obtenerUltimoId() != m.id)
    {
        mensaje reply = {REPLY, m.id};
        PaqueteDatagrama pdUnicast((char *)&reply, sizeof(reply), pd.obtieneDireccion(), UNICAST_PORT);
        // Se genera paquete y se envía.
        socketUnicast.envia(pdUnicast);

        // Cierra socket.
        socketUnicast.~SocketDatagrama();

        // Actualiza último id.
        fijarUltimoId(m.id);
    }
    else
    {
        return -2;
    }

    return recibidos;
}

int SocketMulticast::envia(PaqueteDatagrama &pd, unsigned char ttl)
{
    unsigned char TTL = ttl;
    setsockopt(socketId, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&TTL, sizeof(TTL));

    sockaddr_in direccionGrupo;
    int len = sizeof(direccionGrupo);
    bzero(&direccionGrupo, len);
    direccionGrupo.sin_family = AF_INET;
    direccionGrupo.sin_addr.s_addr = inet_addr(pd.obtieneDireccion());
    direccionGrupo.sin_port = htons(pd.obtienePuerto());

    return sendto(socketId, pd.obtieneDatos(), pd.obtieneLongitud(), 0, (sockaddr *)&direccionGrupo, sizeof(direccionGrupo));
}

/**
 * Envía un paquete de datagrama mediante socket multicast a una determinada cantidad de receptores.
 * Se requiere de un valor TTL para indicar qué tanto se propaga el mensaje.
 * 
 * Retorna la cantidad de bytes enviados o -1 en caso de error.
 */
int SocketMulticast::enviaConfiable(PaqueteDatagrama &pd, unsigned char ttl, int totalReceptores)
{
    SocketDatagrama socketUnicast(UNICAST_PORT);

    PaqueteDatagrama request(MAX_LONGITUD_DATOS);

    int receptoresRestantes = totalReceptores;
    int receptoresActivos = 0;
    int intentos = INTENTOS;
    int enviados;

    while (intentos > 0 && receptoresRestantes > 0)
    {
        for (int i = 0; i < receptoresRestantes; ++i)
        {
            enviados = envia(pd, ttl);
            if (socketUnicast.recibeTimeout(request, 2, 0) >= 0)
            {
                receptoresActivos++;
            }
        }
        receptoresRestantes -= receptoresActivos;
        receptoresActivos = 0;
        intentos--;
    }
    
    return receptoresRestantes == 0 ? enviados : -1;
}

void SocketMulticast::unirAlGrupo(const char *direccionMulticast)
{
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

void SocketMulticast::fijarUltimoId(unsigned int id)
{
    ultimoId = id;
}

unsigned int SocketMulticast::obtenerUltimoId()
{
    return ultimoId;
}