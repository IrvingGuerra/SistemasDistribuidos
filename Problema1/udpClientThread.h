#ifndef UDPCLIENTTHREAD_H
#define UDPCLIENTTHREAD_H

#include "Solicitud.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

struct udpClientArgs
{
    char *ipAddress;
    int rangeSize;
};

void *udpClientThread(void *args);

#endif