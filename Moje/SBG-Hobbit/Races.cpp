#include "Races.h"
#include <iostream>
using namespace std;

Man::Man()
{
    myStats.attack = 1;
    myStats.casualities = 1;
    myStats.defence = 3;
    myStats.strength = 3;
    myStats.courage = 3;
    myStats.fight = 3;
    myStats.move = 6;
    //cout << "Mankonstr";
}

Man::~Man()
{
    //cout << "Mandestr";
}
void Man::virtuality(){
    
}