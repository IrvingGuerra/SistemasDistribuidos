#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>

int puerto = 7200;

int main(void)
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;

   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr("192.168.122.1");
   msg_to_server_addr.sin_port = htons(puerto);

   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;

   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr, sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *)&msg_to_server_addr, sizeof(msg_to_server_addr));

   //char * s_addr_str = mem;
   uint32_t s_addr_server = msg_to_server_addr.sin_addr.s_addr;
   s_addr_server = ntohl(s_addr_server);
   in_port_t s_port_server = msg_to_server_addr.sin_port;
   s_port_server = ntohs(s_port_server);

   printf("servidor: %u.%u.%u.%u:%d\n",
          s_addr_server >> 24 & 0xff,
          s_addr_server >> 16 & 0xff,
          s_addr_server >> 8 & 0xff,
          s_addr_server & 0xff,
          s_port_server);
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);

   //printf();

   printf("2 + 5 = %d\n", res);
   close(s);
}
