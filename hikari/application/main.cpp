#include <hikari/object/object.h>
#include <hikari/object/cube.h>
#include <hikari/renderer/renderer.h>
#include <hikari/engine/engine.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

int main()
{
    hikari::Engine engine;

    hikari::Cube cube;

    engine.putObject(&cube);
    engine.init();
    engine.run();

    return 0;
}