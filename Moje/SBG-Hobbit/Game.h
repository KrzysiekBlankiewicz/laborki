#ifndef GAME_H
#define GAME_H

#include "Unit.h"

class Game
{
    Unit* goodUnits;
    Unit* evilUnits;
public:
    Game();
    void addUnit();
    ~Game();

};

#endif // GAME_H
