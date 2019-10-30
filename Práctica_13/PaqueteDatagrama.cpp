#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama(char *datos, unsigned int longitud, const char *ip, int puerto)
{
    if (longitud > MAX_LONGITUD_DATOS)
    {
        perror("Longitud de datos demasiado grande.");
        exit(EXIT_FAILURE);
    }

    this->datos = new char[longitud];
    memcpy(this->datos, datos, longitud);

    this->longitud = longitud;

    strcpy(this->ip, ip);

    this->puerto = puerto;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud)
{
    if (longitud > MAX_LONGITUD_DATOS)
    {
        perror("Longitud de datos demasiado grande.");
        exit(EXIT_FAILURE);
    }

    this->datos = new char[longitud];

    this->longitud = longitud;
}

const char *PaqueteDatagrama::obtieneDireccion()
{
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud()
{
    return longitud;
}

int PaqueteDatagrama::obtienePuerto()
{
    return puerto;
}

char *PaqueteDatagrama::obtieneDatos()
{
    return datos;
}

void PaqueteDatagrama::inicializaPuerto(int puerto)
{
    this->puerto = puerto;
}

void PaqueteDatagrama::inicializaIp(const char *ip)
{
    strcpy(this->ip, ip);
}

void PaqueteDatagrama::inicializaDatos(char *datos)
{
    memcpy(this->datos, datos, longitud);
}

PaqueteDatagrama::~PaqueteDatagrama()
{
    delete[] datos;
}