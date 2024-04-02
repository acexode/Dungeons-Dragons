#pragma once
#include "Dungeon.h"
#include "Monk.h"
#include <string>

class Game {
public:
    Game();
    void start();
    void explore();

private:
    Dungeon dungeon;
    Monk monk;
};
