#ifndef REGISTRO_H
#define REGISTRO_H

#include <string.h>

struct registro
{
	char celular[11];
	char CURP[19];
	char partido[4];
};

char * registroToString(registro *reg);

#endif