#include "Unit.h"
#include <iostream>
using namespace std;

Unit::Unit()
{
    //cout << "Unitkonstr";
}

Unit::~Unit()
{
    //cout << "Unitdestr";
}

void Unit::print(){
    cout << name << endl << myStats << endl;
}
