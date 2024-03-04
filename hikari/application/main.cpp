#include <hikari/engine/engine.h>
#include <hikari/object/object.h>
#include <hikari/object/cube.h>
#include <hikari/object/cube_light.h>
#include <hikari/object/grass.h>
#include <hikari/object/ocean.h>

int main()
{
    hikari::Engine engine;

    /* Need to make objects detect lights */
    hikari::CubeLight light(1.1f, 3.0f, 2.0f);
    hikari::Cube cube(0.0f, 0.0f, 0.0f);
    hikari::Cube cube2(1.0f, 0.0f, 1.0f);
    // hikari::Grass grass(5.0f, 0.0f, 0.0f);

    hikari::Ocean ocean(0.0f, -3.0f, 0.0f, 64);

    engine.registerObject(&light);
    engine.registerObject(&cube);
    engine.registerObject(&cube2);
    // engine.registerObject(&grass);
    engine.registerObject(&ocean);

    engine.run();

    return 0;
}