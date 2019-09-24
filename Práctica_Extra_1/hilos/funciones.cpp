#include "funciones.h"

void dd(int name_selector)
{
    printf("dd [%d]\n", name_selector);
    char *filenames[2];
    filenames[0] = "c0.txt";
    filenames[1] = "c1.txt";
    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    int fd = open(filenames[name_selector], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (fd == -1)
    {
        perror("Error abriendo archivo para cadenota.");
        exit(-1);
    }

    char *cadenota = create_string(N);

    int len = strlen(cadenota);
    for (register int i = 0; i < len; i++)
    {
        write(fd, cadenota + i, sizeof(char));
    }
    fsync(fd);
    close(fd);
}

void ram()
{
    printf("ram\n");
    int *arreglo, i;
    arreglo = new int[NO_ELEMENTOS];
    for (i = 0; i < NO_ELEMENTOS; i++)
        arreglo[i] = 0;
    for (i = 0; i < 600000000; i++)
    {
        arreglo[rand() % NO_ELEMENTOS] = rand();
    }
}

void cpu()
{
    printf("cpu\n");
    float lo = 0, s = 0, c = 0, t = 0, r2 = 0;
	double i;
	int max = 120000000;
	while (i < max)
	{

		s += sin(i);
		c += cos(i);
		t += tan(i);
		lo += log(i);
		r2 += sqrt(i);
		i++;
	}
}