#include "DatagramPacket.h"

DatagramPacket::DatagramPacket(void *data, unsigned int length, const char *ipAddress, int port)
{
	if (length > MAX_LENGTH)
	{
		perror("Longitud de paquete excede la longitud máxima.");
		exit(EXIT_FAILURE);
	}

	this->data = data;
	this->length = length;
	strcpy(this->ipAddress, ipAddress);
	this->port = port;
}

DatagramPacket::DatagramPacket(unsigned int length)
{
	if (length > MAX_LENGTH)
	{
		perror("Longitud de paquete excede la longitud máxima.");
		exit(EXIT_FAILURE);
	}
	this->data = (void *)new char[length];
	this->length = length;
}

DatagramPacket::~DatagramPacket()
{
	if (data)
		delete [] (char *)data;
}

char *DatagramPacket::getIpAddress()
{
	return ipAddress;
}
unsigned int DatagramPacket::getLength()
{
	return length;
}
int DatagramPacket::getPort()
{
	return port;
}
void *DatagramPacket::getData()
{
	return data;
}
void DatagramPacket::initPort(int port)
{
	this->port = port;
}
void DatagramPacket::initIpAddress(const char *ipAddress)
{
	strcpy(this->ipAddress, ipAddress);
}
void DatagramPacket::initData(void *data)
{
	this->data = data;
}