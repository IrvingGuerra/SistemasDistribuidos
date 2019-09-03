#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define N 27000

char * create_string(int);
int get_occurrences(char *, char *);

int main(int argc, char const *argv[])
{
    srand(getpid());
    char * str = create_string(N);
    int occurences = get_occurrences(str, "IPN");
    printf("Se encontraron %d ocurrencias de IPN.\n", occurences);
    return 0;
}

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

int get_occurrences (char * str, char * pattern)
{
    char * occ = str;
    int occurences = 0;
    while ((occ = strstr(occ, pattern)))
    {
        occ += 4;
        occurences++;
    }
    return occurences;
}