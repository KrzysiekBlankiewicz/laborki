#include "Stats.h"
#include <iostream>
using namespace std;
Stats::Stats()
{
}

Stats::~Stats()
{
}

ostream& operator<<(ostream& os, Stats s){
    os << s.move <<" "<< s.fight <<" "<<s.shoot <<" "<< s.strength <<" "<< s.defence <<" "<< s.attack <<" "<< s.casualities <<" "<< s.courage <<" "<< endl;
}


