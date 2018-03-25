
#include <iostream>
#include "newInt.h"
using namespace std;

int main()
{
    cout << bool(true + 1);
    bigInt x = bigInt(13396), z;
    bigInt y = bigInt(7584);
    x.print();
    y.print();
    if(x > y) cout << "wiekszy" << endl;
    else cout << "mniejszy" << endl;
    if(x < y) cout << "mniejszy" << endl;
    else cout << "wiekszy" << endl;
    z = x + y;
    z.print();
}
