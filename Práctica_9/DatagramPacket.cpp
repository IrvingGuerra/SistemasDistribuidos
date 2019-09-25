#include "DatagramPacket.h"

DatagramPacket::DatagramPacket(char *data, unsigned int length, const char *ipAddress, int port){
	this->data = data;
	this->length = length;
	strcpy(this->ipAddress, ipAddress);
	this->port = port;
}

DatagramPacket::DatagramPacket(unsigned int length){
	this->length = length;
}

DatagramPacket::~DatagramPacket(){
	free(this);
}

char * DatagramPacket::getIpAddress(){
	return ipAddress;
}
unsigned int DatagramPacket::getLength(){
	return length;
}
int DatagramPacket::getPort(){
	return port;
}
char *DatagramPacket::getData(){
	return data;
}
void DatagramPacket::initPort(int port){
	this->port = port;
}
void DatagramPacket::initIpAddress(const char *ipAddress){
	strcpy(this->ipAddress, ipAddress);
}
void DatagramPacket::initData(char *data){
	this->data = data;
}