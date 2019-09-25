#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>

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
    int receive(PaqueteDatagrama &p);
    //Envía un paquete tipo datagrama desde este socket
    int send(PaqueteDatagrama &p);
};