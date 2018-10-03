#ifndef UNIT_H
#define UNIT_H

#include "Stats.h"
#include "structs.h"
#include<string>

class Unit
{
public:
    std::string name;
    Stats myStats;
    XY position;
    bool fighting;
    bool moved;
    Unit();
    virtual void virtuality() = 0;
    virtual void print();
    ~Unit();
};

#endif // UNIT_H
