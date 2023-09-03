#ifndef HANDLER_H
#define HANDLER_H

#include "game_loop.h"

namespace hikari {

class Engine {
private:
    GameLoop* gameLoop;

public:
    Engine();
    ~Engine();
    void runGame();
};

}

#endif HANDLER_H