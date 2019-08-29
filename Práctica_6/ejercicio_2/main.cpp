#include "PoligonoIrregular.h"
#include <algorithm>

int main(int argc, char const *argv[])
{
    int const N = 100;
    PoligonoIrregular p;
    p.anadeVerticesReserve(N);
    cout << "Añadí vértices" << endl;
    p.imprimeVertices();
    cout << "Imprimí vértices desordenados" << endl;
    p.ordenaVertices();
    cout << "Ordené vertices" << endl;
    p.imprimeVertices();
    cout << "Imprimí vértices ordenados" << endl;
    return 0;
}
