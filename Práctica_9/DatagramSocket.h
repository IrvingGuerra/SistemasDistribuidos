#include <arpa/inet.h>

class DatagramSocket
{
private:
    struct sockaddr_in localAddress;
    struct sockaddr_in foreignAddress;
    int socketId; //ID socket
public:
    DatagramSocket(int port);
    ~DatagramSocket();
    //Recibe un paquete tipo datagrama proveniente de este socket
    int recibe(DatagramPacket &p);
    //Envía un paquete tipo datagrama desde este socket
    int envia(DatagramPacket &p);
};