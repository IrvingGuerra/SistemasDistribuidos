#include "Respuesta.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Forma de ejecutar: ./%s  [LISTENING PORT]\n", argv[0]);
    }

    Respuesta respuesta(atoi(argv[1]));
    int nbd = 0;
    while (true)
    {
        // Recibe mensaje.
        mensaje *solicitud = respuesta.getRequest();
        printf("Mensaje recibido.\n");
        // Valida mensaje.
        if (solicitud->messageType != REQUEST)
        {
            perror("El mensaje recibido no es una petición.");
            exit(EXIT_FAILURE);
        }

        // Preparamos respuesta.
        int resultado;
        switch (solicitud->operationID)
        {
        case ADD:
        {
            resultado = ((int *)solicitud->args)[0] + ((int *)solicitud->args)[1];
            break;
        }
        case SUB:
        {
            resultado = ((int *)solicitud->args)[0] - ((int *)solicitud->args)[1];
            break;
        }
        case DEPOSITO:
            nbd += *(int *)solicitud->args;
            resultado = nbd;
        }

        printf("Enviando resultado: %d.\n", resultado);

        // Enviamos resultado.
        respuesta.sendReply((char *)&resultado, sizeof(resultado));
    }

    return 0;
}
