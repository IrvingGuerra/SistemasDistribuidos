#include "Solicitud.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    // int puertoLocal = 6000;

    // SocketDatagrama sd(puertoLocal);

    Solicitud sol();

    // Envía respuesta.
    int _mensaje[2] = {10, 5};
    // int longitudMensaje = 2 * sizeof(int);
    // PaqueteDatagrama saliente((char *)_mensaje, longitudMensaje, "10.100.67.160", 5000);
    // int enviados = sd.envia(saliente);
    // std::cout << "Se enviaron " << enviados << "B" << std::endl;

    char * reply = sol.doOperation("10.100.67.160", 5000, 1, (char *)_mensaje);

    // Recibe datos.
    // PaqueteDatagrama entrante(2 * sizeof(int));
    // int recibidos = sd.recibe(entrante);

    // Log de datos recibidos.
    // const char *dirFuente = reply.obtieneDireccion();
    // int puertoFuente = reply.obtienePuerto();
    // std::cout << "Paquete recibido (" << recibidos << "B)" << std::endl;
    // std::cout << "    Dirección fuente:" << dirFuente << std::endl;
    // std::cout << "    Puerto fuente:" << puertoFuente << std::endl;
    // std::cout << "    Longitud:" << reply.obtieneLongitud() << std::endl;
    // std::cout << "    Datos:" << std::endl;
    // int *datos = (int *)reply.obtieneDatos();
    int * datos = (int *)reply;
    for (unsigned int i = 0; i < sizeof(datos) / sizeof(int); i++)
    {
        std::cout << "        " << i << ":" << datos[i] << std::endl;
    }

    return 0;
}
