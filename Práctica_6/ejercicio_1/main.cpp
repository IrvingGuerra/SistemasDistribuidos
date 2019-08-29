#include "PoligonoIrregular.h"
#include <algorithm>
#define N 1000

bool compare (Coordenada & c1, Coordenada & c2)
{
    return (c1.obtenerMagnitud() < c2.obtenerMagnitud());
}

int main(int argc, char const *argv[])
{
    PoligonoIrregular p;
    p.anadeVerticesReserve(N);
    cout << "Añadí vértices" << endl;
    p.imprimeVertices();
    cout << "Imprimí vértices desordenados" << endl;
    sort(p.obtieneVertices().begin(), p.obtieneVertices().end(), compare);
    cout << "Ordené vertices" << endl;
    p.imprimeVertices();
    cout << "Imprimí vértices ordenados" << endl;
    return 0;
}
