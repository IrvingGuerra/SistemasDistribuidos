#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    int puertoLocal = 5000;

    SocketDatagrama sd(puertoLocal);

    while (true)
    {
        // Recibe datos.
        PaqueteDatagrama entrante(2 * sizeof(int));
        int recibidos = sd.recibe(entrante);

        // Log de datos recibidos.
        const char * dirFuente = entrante.obtieneDireccion();
        int puertoFuente = entrante.obtienePuerto();
        std::cout << "Paquete recibido (" << recibidos << "B)" << std::endl;
        std::cout << "    Dirección fuente:" << dirFuente << std::endl;
        std::cout << "    Puerto fuente:" << puertoFuente << std::endl;
        std::cout << "    Longitud:" << entrante.obtieneLongitud() << std::endl;
        std::cout << "    Datos:" << std::endl;
        int * datos = (int *)entrante.obtieneDatos();
        for (unsigned int i = 0; i < entrante.obtieneLongitud() / sizeof(int); i++)
        {
            std::cout << "        " << i << ":"  << datos[i] << std::endl;
        }

        // Envía respuesta.
        int respuesta[2] = {datos[0] + datos[1], datos[0] - datos[1]};
        int longitudRespuesta = 2 * sizeof(int);
        PaqueteDatagrama saliente((char *)respuesta, longitudRespuesta, dirFuente, puertoFuente);
        int enviados = sd.envia(saliente);
        std::cout << "Se enviaron " << enviados << "B" << std::endl;
    }

    return 0;
}
