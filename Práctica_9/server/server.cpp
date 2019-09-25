#include "DatagramPacket.h"
#include "DatagramSocket.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    // Inicio.
    DatagramSocket socket(6666);
    while (true)
    {

        // Recepción.
        DatagramPacket recvPack(2 * sizeof(int));
        socket.receive(recvPack);
        int *data = (int *)recvPack.getData();
        std::cout << "Dato 1: " << data[0] << std::endl;
        std::cout << "Dato 2: " << data[1] << std::endl;

        // Envío.
        int results[2] = {data[0] + data[1], data[0] - data[1]};
        DatagramPacket sendPack((void *)results, 2 * sizeof(int), "10.100.67.13", 5555);
        socket.send(sendPack);
        std::cout << "Se envió suma y resta" << std::endl;
    }

    // Cierre.
    //sendPack.~DatagramPacket();
    //recvPack.~DatagramPacket();
    //socket.~DatagramSocket();

    return 0;
}
