#include "SocketMulticast.h"

int main(int argc, char const *argv[])
{
    if (argc != 5)
    {
        printf("Uso: ./%s [DIRECCIÓN MULTICAST] [PUERTO PARA ENVIAR] [TTL] [CADENA A ENVIAR]\n",
               argv[0]);
        exit(EXIT_FAILURE);
    }

    // Extracción de parámetros.

    char direccionMulticast[16];
    sprintf(direccionMulticast, "%s", argv[1]);

    int puertoTransmision = atoi(argv[2]);

    unsigned char ttl = (unsigned char)atoi(argv[3]);

    int longitudCadena = strlen(argv[4]);
    char *cadenaParaEnviar = new char[longitudCadena];
    sprintf(cadenaParaEnviar, "%s", argv[4]);

    // Se abre socket.
    SocketMulticast socket(puertoTransmision);
    //socket.unirAlGrupo(direccionMulticast);

    // Se genera paquete y se envía.
    while (true)
    {
        PaqueteDatagrama pd(cadenaParaEnviar, longitudCadena, direccionMulticast, puertoTransmision);
        if (socket.envia(pd, ttl) < 0)
        {
            printf("Error al enviar paquete\n");
            exit(1);
        }
        printf("Se emitió un paquete de datagrama al grupo indicado.\n");
        sleep(1);
    }

    return 0;
}
