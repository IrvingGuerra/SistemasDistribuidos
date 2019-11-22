#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

void ntpdate();

int main() {
    ntpdate();
    return 0;
}

void ntpdate() {
	//char *hostname=(char *)"163.117.202.33";
	//char *hostname=(char *)"pool.ntp.br";
	char    *hostname=(char *)"200.20.186.76";
	int puerto = 123;     //NTP port 123
	int maxlen = 1024;
	unsigned char msg[48] = {010,0,0,0,0,0,0,0,0};
	unsigned long  buf[maxlen];
	struct protoent *proto;     //
	struct sockaddr_in server_addr;
	int s;

	proto = getprotobyname("udp");
	s = socket(PF_INET, SOCK_DGRAM, proto->p_proto);
	perror("socket");

	memset( &server_addr, 0, sizeof( server_addr ));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(hostname);

	server_addr.sin_port = htons(puerto);

	printf("Enviando info NTP...\n");
	sendto(s,msg,sizeof(msg),0,(struct sockaddr *)&server_addr,sizeof(server_addr));
	perror("Enviando.");
	struct sockaddr saddr;
	socklen_t saddr_l = sizeof (saddr);
	recvfrom(s,buf,48,0,&saddr,&saddr_l);
	perror("Recvfr:");

	char timeBuf  [256]; 
	struct timeval tv;
	struct timezone tz;
	struct tm *tm;

	while(true){
		gettimeofday(&tv, &tz);
		tm = localtime(&tv.tv_sec);
		sprintf (timeBuf, "%02d:%02d:%02d.%06ld",tm->tm_hour, tm->tm_min, tm->tm_sec, (tv.tv_usec/1000) );
		printf("%s\n", timeBuf);
	}


}