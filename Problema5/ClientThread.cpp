#include "ClientThread.h"

void *clientThread(void *args)
{
    ClientThreadArgs *ctargs = (ClientThreadArgs *)args;
    // Se prepara el archivo del cual leer el registro.
    int fd = open(ctargs->fileName, O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir archivo con registros");
        exit(EXIT_FAILURE);
    }

    struct stat data;
    int res = fstat(fd, &data);
    if (res == -1)
    {
        perror("Error al obtener metadatos del archivo.");
        close(fd);
        exit(EXIT_FAILURE);
    }
    unsigned int fileSize = data.st_size;

    Solicitud request;
    for (register unsigned int nextReg = 0; nextReg < fileSize; nextReg += 34)
    {
        registro reg;
        int bytesRead = pread(fd, (void *)&reg, 34, nextReg);
        if (bytesRead == -1)
        {
            perror("Error en lectura de siguiente registro.");
            close(fd);
            exit(EXIT_FAILURE);
        }

        bool save = false;
        for (register int i = 0; i < ctargs->numsLen; i++)
        {
            if (reg.celular[9] == ctargs->nums[i])
            {
                save = true;
                break;
            }
        }

        if (save)
        {
            // Se envía la cadena registro.
            timeval *timestamp = (timeval *)request.doOperation(ctargs->ipAdd, ctargs->port, SAVE_REGISTER, (char *)&reg, sizeof(reg));
            printf("Timestamp: %ld:%ld\n", timestamp->tv_sec, timestamp->tv_usec);
        }
    }

    close(fd);

    pthread_exit(nullptr);
}