#include <hikari/engine/engine.h>
#include <hikari/object/object.h>
#include <hikari/object/cube.h>
#include <hikari/object/grass.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

int main()
{
    hikari::Engine engine;

    hikari::Cube cube;
    hikari::Grass grass;

    engine.registerObject(&cube);
    engine.registerObject(&grass);

    // engine.init();

    engine.run();

    return 0;
}