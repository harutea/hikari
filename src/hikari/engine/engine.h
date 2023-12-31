#ifndef ENGINE_H
#define ENGINE_H

#include <hikari/renderer/renderer.h>

namespace hikari
{

    class Engine
    {
    private:
        Renderer *renderer;

    public:
        Engine();
        ~Engine();
        void runGame();
    };

}

#endif HANDLER_H