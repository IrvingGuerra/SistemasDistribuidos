#include <iostream>
using namespace std;

int main (void) {
    double precio = 78.7;
    cout << precio << endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << precio << endl;
    return 0;
}