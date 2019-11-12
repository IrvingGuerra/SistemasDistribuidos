#include "udpClientThread.h"

static void fetchFile(const char *ipAddress)
{
    // Hacemos que el servidor capture pantalla.
    Solicitud solicitud;
    //solicitud.doOperation(ipAddress, 5000, DO_SCREENSHOT, (char *)&quality, sizeof(quality));

    // Obtenemos tamaño en bites de imagen.
    char *length = solicitud.doOperation(ipAddress, 5000, GET_IMAGE_LENGTH, nullptr, 0);

    // Casteamos la longitud de imagen.
    int fileLength = *(int *)length;

    // Preparamos variables para recibir archivo por chunks.
    int amountOfChunks = fileLength / MAX_DATA_SIZE;
    int extraChunk = fileLength % MAX_DATA_SIZE;
    std::string fileName = ipAddress;
    fileName = "./regRecv.txt";

    // Creamos archivo para ir guardando datos.
    std::ofstream file(fileName);
    file.close();
    file.open(fileName, std::ios::out | std::ios::binary | std::ios::app);
    if (!file)
    {
        perror("Error al abrir archivo para escritura.");
        exit(EXIT_FAILURE);
    }

    // Recibimos conjunto de datos de tamaño MAX_DATA_SIZE según se requiera.
    for (register int i = 0; i < amountOfChunks; i++)
    {
        char *data = solicitud.doOperation(ipAddress, 5000, GET_IMAGE_CHUNK, (char *)&i, sizeof(i));
        file.write(data, MAX_DATA_SIZE);
    }

    // En caso de que la longitud del archivo no sea multiplo de MAX_DATA_SIZE,
    // recibimos un último paquete.
    if (extraChunk)
    {
        char *data = solicitud.doOperation(ipAddress, 5000, GET_IMAGE_CHUNK, (char *)&amountOfChunks, sizeof(amountOfChunks));
        //file.seekp(std::ios::ate);
        file.write(data, extraChunk);
    }

    // Cerramos archivo.
    file.close();
}

void *udpClientThread(void *args)
{
    printf("Cliente udp corre.\n");
    // Casteamos los argumentos.
    udpClientArgs *_args = (udpClientArgs *)args;

    std::string ipAddress = _args->ipAddress;
    fetchFile(ipAddress.c_str());

    // Salimos del hilo sin regresar nada.
    pthread_exit((void *)nullptr);
}
