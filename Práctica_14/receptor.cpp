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

    // Base de datos.
    int dinero = 0;

    // Se prepara un paquete para recibir depósitos.
    PaqueteDatagrama pd(MAX_LONGITUD_DATOS);

    // Ciclo de recepción para depósitos.
    while (true)
    {
        // Se recibe el paquete.
        int resultado = socket.recibeConfiable(pd);

        // Se valida estado de recepción.
        if (resultado == -1)
        {
            printf("Error al recibir paquete.\n");
            exit(1);
        }
        else if (resultado == -2)
        {
            printf("Mensaje recibido de nuevo.\n");
        }
        else // Se actualiza el dinero.
        {
            mensaje m = *(mensaje *)pd.obtieneDatos();
            int valorDeposito = *(int *)m.args;
            dinero += valorDeposito;
            printf("Depósito de %d. Dinero: %d\n", valorDeposito, dinero);
        }
    }

    return 0;
}
