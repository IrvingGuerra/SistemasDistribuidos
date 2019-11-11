#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char const *argv[])
{

    if (argc != 3)
    {
        printf("Uso: ./%s [DIRECCIÓN MULTICAST] [PUERTO DE ESCUCHA]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Extracción de parámetros.
    char direccionMulticast[16];
    sprintf(direccionMulticast, "%s", argv[1]);

    int puertoRecepcion = atoi(argv[2]);

    // Se crea socket y se une a grupo.
    SocketMulticast socket(puertoRecepcion);
    socket.unirAlGrupo(direccionMulticast);

    // Se prepara un paquete para recibir y se imprime origen.
    PaqueteDatagrama pd(MAX_LONGITUD_DATOS);

    if (socket.recibeConfiable(pd) < 0)
    {
        printf("Error al recibir paquete\n");
        exit(1);
    }

    return 0;
}
