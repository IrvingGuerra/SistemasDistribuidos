#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#define MAX_LONGITUD_DATOS 16376

int main(void)
{
   int puerto = 5000;
   int num[2];
   int s, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;

   s = socket(AF_INET, SO_BROADCAST, 0);
   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   while (1)
   {
      recvfrom(s, (int *)num, 2 * sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);

      // Guarda direccción fuente.
      uint32_t direccionFuente = ntohl(msg_to_client_addr.sin_addr.s_addr);
      char direccionFuenteCadena[16];
      sprintf(direccionFuenteCadena, "%u.%u.%u.%u",
              direccionFuente >> 24 & 0xff,
              direccionFuente >> 16 & 0xff,
              direccionFuente >> 8 & 0xff,
              direccionFuente & 0xff);

      // Guarda puerto fuente.
      in_port_t puertoFuente = ntohs(msg_to_client_addr.sin_port);

      if (strcmp(direccionFuenteCadena, "10.100.78.55") == 0)
      {
         printf("Paquete recibido de cliente: %s:%d\n", direccionFuenteCadena, puertoFuente);

         int res[2] = {num[0] + num[1], num[0] - num[1]};
         printf("Suma: %d\n", res[0]);
         printf("Resta: %d\n", res[1]);

         /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
         sendto(s, (char *)res, 2 * sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);

         printf("Respuesta enviada.\n");
      }
   }
}
