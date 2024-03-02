#include <hikari/engine/engine.h>
#include <hikari/object/object.h>
#include <hikari/object/cube.h>
#include <hikari/object/grass.h>

int main()
{
    hikari::Engine engine;

    hikari::Cube cube(0.0f, 0.0f, 0.0f);
    hikari::Cube cube2(1.0f, 0.0f, 1.0f);
    hikari::Grass grass;

    engine.registerObject(&cube);
    engine.registerObject(&cube2);
    engine.registerObject(&grass);

    engine.run();

    return 0;
}