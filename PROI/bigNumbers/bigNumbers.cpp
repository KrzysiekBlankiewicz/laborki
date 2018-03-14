
#include <iostream>
#include "newInt.h"
using namespace std;

int main()
{
    bigInt x = bigInt(523356), z;
    bigInt y = bigInt(787684);
    x.print();
    y.print();
    z = x + y;
    z.print();
    cout << (int)z.getPosition(6);
}
