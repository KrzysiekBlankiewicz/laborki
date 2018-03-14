
#include <iostream>
#include "newInt.h"
using namespace std;

int main()
{
    bigInt x {3356};
    bigInt y {36739};
    x.print();
    //y.print();
    cout << (int)x.getPosition(5);
}
