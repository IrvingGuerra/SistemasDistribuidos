#include "Solicitud.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    // int puertoLocal = 6000;

    // SocketDatagrama sd(puertoLocal);

    Solicitud sol;

    // Envía respuesta.
    int _mensaje[5] = {0, 0, 1, 4, 5};
    // int longitudMensaje = 2 * sizeof(int);
    // PaqueteDatagrama saliente((char *)_mensaje, longitudMensaje, "10.100.67.160", 5000);
    // int enviados = sd.envia(saliente);
    // std::cout << "Se enviaron " << enviados << "B" << std::endl;

    char address[] = "192.168.0.2";

    char *respuesta = sol.doOperation((char *)address, 5000, 1, (char *)_mensaje);

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

    int * datos = (int *)respuesta;

    std::cout << "El resultado es: :"  << datos[0] << std::endl;


    return 0;
}
