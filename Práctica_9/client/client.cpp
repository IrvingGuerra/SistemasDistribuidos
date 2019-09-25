#include "DatagramPacket.h"
#include "DatagramSocket.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    // Inicio.
    DatagramSocket socket(5555);

    // Envío.
    int data[2] = {10, 5};
    DatagramPacket sendPack((void *)data, 2 * sizeof(int), "10.100.67.13", 6666);
    DatagramPacket recvPack(2 * sizeof(int));
    socket.send(sendPack);

    // Recepción.
    socket.receive(recvPack);
    int * results = (int *) recvPack.getData();
    std::cout << "Suma: " << results[0] << std::endl;
    std::cout << "Resta: " << results[1] << std::endl;

    // Cierre.
    //sendPack.~DatagramPacket();
    //recvPack.~DatagramPacket();
    //socket.~DatagramSocket();

    return 0;
}
