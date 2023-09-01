#include <hikari/physics/object.h>
#include <hikari/renderer/renderer.h>
#include <hikari/engine/handler.h>

using namespace hikari;

int main()
{
    EngineHandler handler;
    while(handler.getRunningState() == ENGINE_RUNNING) {
        handler.processInput();
        handler.update();
        handler.render();
    }
    return 0;
}