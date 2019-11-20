#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Solicitud.h"
#include "mensaje.h"
#include "registro.h"

#define SERVER_PORT 5000

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		printf("Uso: ./%s <archivo con registros> <no. registros por enviar> <dirección IP servidor> \n", argv[0]);
		exit(0);
	}

	// Se prepara el archivo del cual leer el registro.
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir archivo con registros");
		exit(EXIT_FAILURE);
	}

	// Cantidad de lecturas.
	int n = atoi(argv[2]);

	Solicitud request;
	request.doOperation(argv[3], SERVER_PORT, SEND_REGS_QUANTITY, (char *)&n, sizeof(n));

	for (register int i = 0; i < n; i++)
	{
		// Se lee el registro (siguientes 34 bytes).
		registro reg;
		int bytesRead = pread(fd, (void *)&reg, 34, 34 * i);
		if (bytesRead == -1)
		{
			perror("Error en lectura de siguiente registro.");
			close(fd);
			exit(EXIT_FAILURE);
		}

		// Se da tratamiento al registro para que sea cadena imprimible.
		// char *regString = registroToString(&reg);
		// printf("Se enviará cadena: %s\n", regString);

		// Se envía la cadena registro.
		timeval *timestamp = (timeval *)request.doOperation(argv[3], SERVER_PORT, SAVE_REGISTER, (char *)&reg, sizeof(reg));
		// printf("Timestamp %d: %ld:%ld\n", i, timestamp->tv_sec, timestamp->tv_usec);
	}

	close(fd);

	return 0;
}
