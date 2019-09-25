#ifndef DATAGRAMPACKET_H_
#define DATAGRAMPACKET_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LENGTH 16376

class DatagramPacket
{
private:
	void *data;		   //Almacena los datos
	char ipAddress[16];		   //Almacena la IP
	unsigned int length; //Almacena la longitude de la cadena de datos
	int port;			   //Almacena el puerto
public:
	DatagramPacket(void * data, unsigned int length, const char * ip, int port);
	DatagramPacket(unsigned int length);
	~DatagramPacket();
	char *getIpAddress();
	unsigned int getLength();
	int getPort();
	void *getData();
	void initPort(int port);
	void initIpAddress(const char * ip);
	void initData(void * data);
};

#endif