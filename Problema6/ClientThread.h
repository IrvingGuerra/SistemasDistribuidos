#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Solicitud.h"
#include "mensaje.h"
#include "registro.h"

struct ClientThreadArgs
{
    char nums[4];
    int numsLen;
    const char *ipAdd; //[16];
    int port;
    const char *fileName; //[20];
};

void *clientThread(void *args);

#endif