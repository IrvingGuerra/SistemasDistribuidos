#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    double c = 20;
    double f;
    f = (double)(9)/5 * c + 32.0;
    cout << f << endl;
    f = static_cast<double>(9)/5 * c + 32.0;
    cout << f << endl;
    return 0;
}