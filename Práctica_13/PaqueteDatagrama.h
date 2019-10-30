#ifndef PAQUETEDATAGRAMA_H
#define PAQUETEDATAGRAMA_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LONGITUD_DATOS 16376

class PaqueteDatagrama
{
public:
    PaqueteDatagrama(char *, unsigned int, const char *, int);
    PaqueteDatagrama(unsigned int longitud);
    ~PaqueteDatagrama();
    const char *obtieneDireccion();
    unsigned int obtieneLongitud();
    int obtienePuerto();
    char *obtieneDatos();
    void inicializaPuerto(int);
    void inicializaIp(const char *);
    void inicializaDatos(char *);

private:
    char *datos;
    //Almacena los datos
    char ip[16];
    //Almacena la IP
    unsigned int longitud;
    //Almacena la longitude de la cadena de datos
    int puerto;
    //Almacena el puerto
};

#endif
