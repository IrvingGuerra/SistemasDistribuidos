#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char const *argv[])
{   
    if (argc != 5)
    {
        printf("Uso: ./%s [DIRECCIÓN MULTICAST] [PUERTO PARA ENVIAR] [TTL]\n",
               argv[0]);
        exit(EXIT_FAILURE);
    }

    // Extracción de parámetros.
     //int semilla = time(NULL);
    srand(getpid());
    int deposito;
    int num_depositos = atoi(argv[4]);
    char direccionMulticast[16];
    sprintf(direccionMulticast, "%s", argv[1]);

    int puertoTransmision = atoi(argv[2]);

    unsigned char ttl = (unsigned char)atoi(argv[3]);
/*
    int longitudCadena = strlen(argv[4]);
    char *cadenaParaEnviar = new char[longitudCadena];
    sprintf(cadenaParaEnviar, "%s", argv[4]);
*/
    // Se abre socket.
    SocketMulticast socket(puertoTransmision);
    //socket.unirAlGrupo(direccionMulticast);

    // Se genera paquete y se envía.
//enviados
    PaqueteDatagrama pd((char*)&num_depositos, sizeof(deposito), direccionMulticast, puertoTransmision);
    if(socket.enviaConfiable(pd, ttl, 2) < 0){
        printf("Error al enviasalirDelGrupor paquete\n");
        exit(1);
    }

    deposito = rand() % 9 + 1;
    for(int i = 0; i < num_depositos; i++){

        printf("cantidad: %d y numero de depositos: %d\n", deposito, num_depositos);

        PaqueteDatagrama pd((char*)&deposito, sizeof(deposito), direccionMulticast, puertoTransmision);
/*
    if (socket.envia(pd, ttl) < 0)
    {
        printf("Error al enviasalirDelGrupor paquete\n");
        exit(1);
    }
    printf("Se emitió un paquete de datagrama al grupo indicado.\n");


    SocketDatagrama socketUnicast(6000);
    PaqueteDatagrama request(MAX_LONGITUD_DATOS);

    for (int i = 0; i < 5; ++i)
    {
        socketUnicast.recibe(request);
        printf("Si recibi respuesta de: %s\n",request.obtieneDireccion());
    }
        

    if(socket.enviaConfiable(pd, ttl, 1) < 0){
        printf("Error, no todos los miembros del grupo recibieron el paquete");
        exit(1);
    }
    printf("Se envio el mensaje exitosamente");
*/
       if(socket.enviaConfiable(pd, ttl, 1) < 0){
        printf("Error al enviasalirDelGrupor paquete\n");
        exit(1);
        }
    }
    return 0;
}
