#include <iostream>
#include "newInt.h"

using namespace std;

bigInt::bigInt()
{
    for(int i = 0; i < N; i++){
        tab[i] = 0;
    }
}
//bigInt(std::string input);
bigInt::bigInt(int input){
    bigInt();
    for(int i = 1; input > 0; i++){
        tab[N-i] = static_cast<unsigned char>(input%10);
        input = input/10;
    }
}

void bigInt::print()
{
    for(int i = 0; i < N; i++){
        std::cout<<static_cast<int>(tab[i]);
    }
    std::cout << endl << endl;
}

void bigInt::setPosition(int i, unsigned char c)
{
    tab[i] = c;
}

unsigned char bigInt::getPosition(int i)
{
    return tab[i];
}

bigInt operator+(bigInt x, bigInt y)
{
    bigInt sum;
    int help;
    for(int i = 0; i > N; i++)
    {
        help = (int)x.getPosition(i) + (int)y.getPosition(i);
        sum.setPosition(i, (unsigned char)help);
    }
    return sum;
}
