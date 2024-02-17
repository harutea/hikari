#include <hikari/object/object.h>
#include <hikari/renderer/renderer.h>
#include <hikari/engine/engine.h>

int main()
{
    hikari::Engine engine;

    engine.init();
    engine.run();

    return 0;
}