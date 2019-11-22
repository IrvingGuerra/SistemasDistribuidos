#include <fstream>
#include <iostream>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <set>
#include <vector>
#include <algorithm>

#include "Respuesta.h"
#include "registro.h"

#define SERVER_PORT 5000

int main(int argc, char const *argv[])
{

    Respuesta response(SERVER_PORT);
    mensaje *receiver;

    unsigned int prevReqID;
    //bool hasPrevReqID = false;

    std::set<long> numeros; // sss
    // std::vector<long> numeros; // vvv

    int fd = open("registros.data", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("Error al abrir el archivo de registros.\n");
        exit(EXIT_FAILURE);
    }

    for (;;)
    {
        receiver = response.getRequest();

        if (receiver->operationID != SAVE_REGISTER)
        {
            perror("Se esperaba un registro para guardar.");
            close(fd);
            exit(EXIT_FAILURE);
        }

        registro *reg = (registro *)receiver->args;
        timeval timestamp;

        // Validación Set
        std::set<long>::iterator num = numeros.find(atol(reg->celular)); // sss

        // Validación Vector
        // bool found = std::binary_search(numeros.begin(), numeros.end(), atol(reg->celular)); // vvv
        if (prevReqID != receiver->requestID)
        {
            if (num != numeros.end()) // sss
            // if (found && prevReqID != receiver->requestID) // vvv
            {
                printf("Número ya existente\n");
                timestamp.tv_sec = 0;
                timestamp.tv_usec = 0;
            }
            else
            {
                // printf("Registro nuevo recibido: %s\n", registroToString(reg));
                write(fd, reg, sizeof(registro));
                //fsync(fd);
                gettimeofday(&timestamp, NULL);
                // Set
                numeros.insert(atol(reg->celular)); // sss

                // Vector
                // long phone = atol(reg->celular); // vvv
                // std::vector<long>::iterator pos = std::lower_bound(numeros.begin(), numeros.end(), phone); // vvv
                // numeros.insert(pos, phone); // vvv
            }
        }
        //printf("Enviando timestamp.\n");
        prevReqID = receiver->requestID;
        //hasPrevReqID = true;
        response.sendReply((char *)&timestamp, sizeof(timeval));
    }

    close(fd);
    return 0;
}
