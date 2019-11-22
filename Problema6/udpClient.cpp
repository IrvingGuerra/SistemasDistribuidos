#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Solicitud.h"
#include "mensaje.h"
#include "registro.h"
#include "ClientThread.h"

#define SERVER_PORT 5000

int main(int argc, char const *argv[])
{
	if (argc != 5)
	{
		printf("Uso: ./%s <archivo con registros> <dir. IP serv. 1> <dir. IP serv. 2> <dir. IP serv. 3> \n", argv[0]);
		exit(0);
	}

	ClientThreadArgs ctargsA = {
		{'0', '1', '2', '3'},
		4,
		argv[2],
		SERVER_PORT,
		argv[1]};
	ClientThreadArgs ctargsB = {
		{'4', '5', '6'},
		3,
		argv[3],
		SERVER_PORT,
		argv[1]};
	ClientThreadArgs ctargsC = {
		{'7', '8', '9'},
		3,
		argv[4],
		SERVER_PORT,
		argv[1]};

	pthread_t tids[3];
	void *resps[3];
	pthread_create(tids, nullptr, clientThread, (void *)&ctargsA);
	pthread_create(tids + 1, nullptr, clientThread, (void *)&ctargsB);
	pthread_create(tids + 2, nullptr, clientThread, (void *)&ctargsC);
	pthread_join(tids[0], &resps[0]);
	pthread_join(tids[1], &resps[1]);
	pthread_join(tids[2], &resps[2]);
	return 0;
}
