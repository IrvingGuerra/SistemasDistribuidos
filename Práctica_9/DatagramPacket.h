#ifndef DATAGRAMPACKET_H_
#define DATAGRAMPACKET_H_

#include <stdlib.h>
#include <string.h>

class DatagramPacket
{
private:
	char *data;		   //Almacena los datos
	char ipAddress[16];		   //Almacena la IP
	unsigned int length; //Almacena la longitude de la cadena de datos
	int port;			   //Almacena el puerto
public:
	DatagramPacket(char * data, unsigned int length, const char * ip, int port);
	DatagramPacket(unsigned int length);
	~DatagramPacket();
	char *getIpAddress();
	unsigned int getLength();
	int getPort();
	char *getData();
	void initPort(int port);
	void initIpAddress(const char * ip);
	void initData(char * data);
};

#endif