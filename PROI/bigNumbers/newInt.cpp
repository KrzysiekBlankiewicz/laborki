#include <iostream>
#include "newInt.h"

using namespace std;

bigInt::bigInt()
{
    for(int i = 0; i < N; i++){
        tab[i] = 0;
    }
    invalid = false;
}
//bigInt(std::string input);
bigInt::bigInt(int input){
    bigInt();
    for(int i = 1; i < N+1; i++){
        tab[N-i] = static_cast<unsigned char>(input%10);
        //cout << (int)tab[N-i] << " ";
        input = input/10;
    }
    //cout << endl;
    invalid = false;
}

void bigInt::print()
{
    for(int i = 0; i < N; i++){
        std::cout << static_cast<int>(tab[i]) << " ";
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

bigInt bigInt::operator+(bigInt y)
{
    bigInt sum;
    int help, helpUpgraded;
    int carriage = 0;
    for(int i = N-1; i >= 0; i--)
    {
        help = (int)tab[i] + (int)y.getPosition(i) + carriage;
        helpUpgraded = help%10;
        if(helpUpgraded != help) carriage = 1;
        else carriage = 0;
        sum.setPosition(i, (unsigned char)helpUpgraded);
    }
    //if(carriage != 0) invalid = true;
    return sum;
}
