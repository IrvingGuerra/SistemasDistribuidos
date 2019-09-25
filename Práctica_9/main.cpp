#include "DatagramPacket.h"
#include "DatagramSocket.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    int data[2] = {10, 5};
    DatagramPacket sendPack((char *)data, 2 * sizeof(int), "ip add", 6666);
    DatagramPacket recvPack(2);
    
    DatagramSocket socket(5555);
    socket.send(sendPack);
    socket.receive(recvPack);

    int * results = (int *) recvPack.getData();
    std::cout << "Suma: " << results[0] << std::endl;
    std::cout << "Resta: " << results[1] << std::endl;

    sendPack.~DatagramPacket();
    recvPack.~DatagramPacket();
    socket.~DatagramSocket();

    return 0;
}
