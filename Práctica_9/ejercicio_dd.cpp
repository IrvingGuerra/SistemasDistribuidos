#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

#define N 1757600

using namespace std;

char buffer[BUFSIZ];

char * create_string(int);

int main(int argc, char *argv[])
{
    srand(getpid());

    int destino;
    string linea;
    if (argc != 2)
    {
        cout << "Forma de uso: " << argv[0] << " [0: por byte, 1:por token, 2:por BUFSIZ]\n";
        exit(0);
    }

    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if ((destino = open("cadenota.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
    {
        perror("Error abriendo archivo para cadenota.");
        exit(-1);
    }

    char * cadenota = create_string(N);

    switch (atoi(argv[1]))
    {
    case 0:
    {
        int len = strlen(cadenota);
        printf("Longitud de cadena: %d\n", len);
        for (register int i = 0; i < len; i++)
        {
            write(destino, cadenota + i, sizeof(char));
        }
        fsync(destino);
        close(destino);
        break;
    }
    case 1:
    {
        printf("Tokens: %d\n", N);
        for (register int i = 0; i < N; i++)
        {
            write(destino, cadenota + i*4, sizeof(char) * 4);
        }
        fsync(destino);
        close(destino);
        break;
    }
    case 2:
    {
        int len = strlen(cadenota);
        int buffers = len / BUFSIZ;
        int resto = len % BUFSIZ;

        printf("Longitud de cadena: %d\n", len);
        for (register int i = 0; i < buffers; i++)
        {
            write(destino, cadenota + i * BUFSIZ, sizeof(char) * BUFSIZ);
        }
        write(destino, cadenota + buffers * BUFSIZ, sizeof(char) * resto);
        
        fsync(destino);
        close(destino);
        break;
    }
    default:
        printf("Opción no válida, intente con 0, 1 o 2\n");
        break;
    }
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
