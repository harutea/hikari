#ifndef ENGINE_H
#define ENGINE_H

#include <hikari/renderer/renderer.h>
#include <hikari/object/object.h>

namespace hikari
{

    class Engine
    {
    private:
        Renderer *renderer;

    public:
        Engine();
        ~Engine();
        void init();
        void run();
        void registerObject(Object *object);
    };

}

#endif ENGINE_H