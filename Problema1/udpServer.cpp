#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Respuesta.h"

int main(int argc, char const *argv[])
{
    Respuesta response(5000);
    mensaje *msgRegister = response.getRequest();
    printf("Se recibió un registro:\n\t%s\n", msgRegister->args);
    char reply[2] = "1";
    response.sendReply(reply, 2);
    int fd = open("registro.data", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    write(fd, msgRegister->args, strlen(msgRegister->args));
    return 0;
}
