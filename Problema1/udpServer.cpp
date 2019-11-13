#include <fstream>
#include <iostream>

#include "Respuesta.h"

int main(int argc, char const *argv[])
{
    Respuesta response(5000);
    mensaje *msgRegister = response.getRequest();
    printf("Se recibió un registro:\n\t%s\n", msgRegister->args);
    char reply[2] = "a";
    response.sendReply(reply, 2);
    return 0;
}
