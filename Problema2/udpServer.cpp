#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Respuesta.h"
#include "registro.h"

#define SERVER_PORT 5000

int main(int argc, char const *argv[])
{

    Respuesta response(SERVER_PORT);
    mensaje *receiver;

    receiver = response.getRequest();
    if (receiver->operationID != SEND_REGS_QUANTITY)
    {
        char err[6] = "ERROR";
        response.sendReply(err, sizeof(err));
        perror("Se esperaba la cantidad de registros por recibir.");
        exit(EXIT_FAILURE);
    }
    char reply[3] = "OK";
    response.sendReply(reply, sizeof(reply));

    int fd = open("registros.data", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("Error al abrir el archivo de registros.\n");
        exit(EXIT_FAILURE);
    }

    int n = *(int *)receiver->args;
    for (register int i = 0; i < n; i++)
    {
        receiver = response.getRequest();
        if (receiver->operationID != SAVE_REGISTER)
        {
            perror("Se esperaba un registro para guardar.");
            close(fd);
            exit(EXIT_FAILURE);
        }

        registro *reg = (registro *)receiver->args;
      //  printf("Registro recibido: %s\n", registroToString(reg));
        write(fd, receiver->args, sizeof(registro));

        char reply[20];
        sprintf(reply, "GUARDADO %d", i);
        response.sendReply(reply, strlen(reply));
    }

    close(fd);
    return 0;
}
