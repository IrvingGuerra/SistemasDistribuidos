#include <iostream>
#include <fstream>

#include "Solicitud.h"
#include "mensaje.h"

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		printf("Uso: ./%s <archivo a enviar> <dirección IP de servidor> <puerto servidor>\n", argv[0]);
		exit(0);
	}

	// Se prepara el archivo del cual leer el registro.
	std::ifstream regFile(argv[1], std::ios::binary);
	if (!regFile.is_open())
	{
		printf("Error al abrir archivo.\n");
		exit(0);
	}

	// Se lee el registro (34 bytes) y se cierra archivo.
	char reg[34];
	regFile.read(reg, 34);
	regFile.close();

	// Se da tratamiento al registro para que sea cadena.
	char regClean[32] = "";
	strcat(regClean, reg);
	strcat(regClean, reg + 11);
	strcat(regClean, reg + 30);

	printf("Se enviará cadena: %s\n", regClean);

	// Se envía la cadena registro.
	Solicitud request;
	request.doOperation(argv[2], atoi(argv[3]), SAVE_REGISTER, (char *)regClean, 32);

	return 0;
}
