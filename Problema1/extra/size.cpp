#include <iostream>

struct registro
{
    char celular[11];
    char CURP[19];
    char partido[4];
};

int main(int argc, char const *argv[])
{
    int size = 7000000 * sizeof(registro);
    double parsed = (double)size / (1024 * 1024);
    std::cout << "Tamaño nacesario en bytes para 7,000,000: " << size << std::endl;
    std::cout << "Tamaño nacesario en MB para 7,000,000: " << parsed << std::endl;


    return 0;
}
