#ifndef STATS_H
#define STATS_H

#include <iostream>

class Stats
{

public:
    Stats();
    ~Stats();
    int move;
    int fight; 
    int shoot;
    int strength; 
    int defence; 
    int attack;
    int casualities;
    int courage;
    
    friend std::ostream& operator<<(std::ostream& os, Stats s);
};

#endif // STATS_H
