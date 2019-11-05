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
    if (socket.recibe(pd) < 0) {
        printf("Error al recibir paquete\n");
        exit(1);
    }

    char dirFuente[16];
    sprintf(dirFuente, "%s", pd.obtieneDireccion());

    printf("\nSe recibió un paquete en el grupo.\n");
    printf("\tOrigen: %s:%d\n", dirFuente, pd.obtienePuerto());
    printf("\tContenido: %s.\n", pd.obtieneDatos());



    socket.salirDelGrupo(direccionMulticast);

 
    // Se abre socket.
    SocketDatagrama socketUnicast(7000);

    // Se genera paquete y se envía.

    PaqueteDatagrama pdUnicast("Si recibi dato \n", strlen("Si recibi dato \n"), dirFuente, 6000);

  
    socketUnicast.envia(pdUnicast);
    sleep(1);
  
    

    return 0;
}
