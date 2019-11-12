#include "Respuesta.h"
#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    Respuesta respuesta(5000);
    std::string fileName = "./extra/reg.txt";
    // Preparamos respuesta.
    void *resultado = nullptr;
    int resultadoLen;
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

        if (respuesta.newRequest || resultado == nullptr)
        {
            switch (solicitud->operationID)
            {
            case DO_SCREENSHOT:
            {
                int quality = *(int *)solicitud->args;
                char cmd[100];
                sprintf(cmd, "scrot '%s' -q %d", fileName.c_str(), quality);
                system(cmd);
                resultadoLen = 1;
                resultado = new char[resultadoLen];
                *(char *)resultado = '0';
                break;
            }
            case GET_IMAGE_LENGTH:
            {
                std::ifstream file(fileName, std::ios::binary | std::ios::ate);
                if (!file)
                {
                    exit(EXIT_FAILURE);
                }
                int len = file.tellg();
                resultadoLen = sizeof(len);
                resultado = new int[1];
                *(int *)resultado = len;
                file.close();
                break;
            }
            case GET_IMAGE_CHUNK:
            {
                // Se identifica el segmento del archivo que se pidió.
                int chunk = *(int *)(solicitud->args);

                // Se abre archivo para saber su longitud.
                std::ifstream file(fileName, std::ios::binary | std::ios::ate);
                if (!file)
                {
                    exit(EXIT_FAILURE);
                }
                int fileSize = file.tellg();

                // Nos posicionamos en el chunk adecuado.
                file.seekg(chunk * MAX_DATA_SIZE, std::ios::beg);
                int unsentBytes = fileSize - chunk * MAX_DATA_SIZE;
                resultadoLen = unsentBytes < MAX_DATA_SIZE ? unsentBytes : MAX_DATA_SIZE;

                // Obtenemos los datos.
                resultado = new char[resultadoLen];
                file.read((char *)resultado, resultadoLen);
                file.close();
                break;
            }
            }
            printf("Enviando resultado\n");
        }
        else
        {
            printf("Reenviando resultado\n");
        }

        // Enviamos resultado.
        respuesta.sendReply((char *)resultado, resultadoLen);
        //free(resultado);
    }

    return 0;
}
