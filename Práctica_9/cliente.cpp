#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    int puertoLocal = 6000;

    SocketDatagrama sd(puertoLocal);

    // Envía respuesta.
    int mensaje[2] = {10, 5};
    int longitudMensaje = 2 * sizeof(int);
    PaqueteDatagrama saliente((char *)mensaje, longitudMensaje, "10.211.222.169", 5000);
    int enviados = sd.envia(saliente);
    std::cout << "Se enviaron " << enviados << "B" << std::endl;

    // Recibe datos.
    PaqueteDatagrama entrante(2 * sizeof(int));
    int recibidos = sd.recibe(entrante);

    // Log de datos recibidos.
    const char *dirFuente = entrante.obtieneDireccion();
    int puertoFuente = entrante.obtienePuerto();
    std::cout << "Paquete recibido (" << recibidos << "B)" << std::endl;
    std::cout << "    Dirección fuente:" << dirFuente << std::endl;
    std::cout << "    Puerto fuente:" << puertoFuente << std::endl;
    std::cout << "    Longitud:" << entrante.obtieneLongitud() << std::endl;
    std::cout << "    Datos:" << std::endl;
    int *datos = (int *)entrante.obtieneDatos();
    for (unsigned int i = 0; i < entrante.obtieneLongitud() / sizeof(int); i++)
    {
        std::cout << "        " << i << ":" << datos[i] << std::endl;
    }

    return 0;
}
