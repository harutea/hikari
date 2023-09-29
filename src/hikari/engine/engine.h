#ifndef ENGINE_H
#define ENGINE_H

#include "game_loop.h"

namespace hikari
{

    class Engine
    {
    private:
        GameLoop *gameLoop;

    public:
        Engine();
        ~Engine();
        void runGame();
    };

}

#endif HANDLER_H