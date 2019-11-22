#include "registro.h"

char *registroToString(registro *reg)
{
    char *regString = new char[32];
    regString[0] = 0;
    strcat(regString, reg->celular);
    strcat(regString, reg->CURP);
    strcat(regString, reg->partido);
    return regString;
}