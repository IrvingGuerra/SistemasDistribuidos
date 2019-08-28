#include "PoligonoIrregular.h"

#define N 10000

int main(int argc, char const *argv[])
{
    vector<PoligonoIrregular> ps1;
    vector<PoligonoIrregular> ps2;
    // Push
    if (atoi(argv[1]) == 0)
    {
        for (int i = 0; i < N; i++)
        {
            ps1.push_back(PoligonoIrregular());
            ps1[i].anadeVerticesPush(N);
        }
    }

    // Reserve
    if (atoi(argv[1]) == 1)
    {
        ps2.reserve(N);
        for (int i = 0; i < N; i++)
        {
            ps2[i].anadeVerticesReserve(N);
        }
    }

    cout << PoligonoIrregular::cuentaVertices << endl;

    return 0;
}
