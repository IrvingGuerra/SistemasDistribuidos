#include "cadenota.h"

char *create_string(int n)
{
    char *str = NULL;
    for (register int i = 0; i < N; i++)
    {
        str = (char *)realloc(str, 4 * (i + 1));
        for (register int j = 0; j < 3; j++)
        {
            register char c = 'A' + rand() % 26;
            *(str + 4 * i + j) = c;
        }
        *(str + 4 * i + 3) = ' ';
    }
    const int len = n * 4;
    str = (char *)realloc(str, len + 1);
    *(str + len) = 0; // Fin de cadena.
    
    return str;
}
