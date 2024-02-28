#include "engine.h"

using namespace hikari;

Engine::Engine()
{
    this->renderer = new Renderer;
}

Engine::~Engine()
{
    delete renderer;
}

void Engine::init()
{
}

void Engine::run()
{
    this->renderer->setup();
    this->renderer->render();
    this->renderer->clear();
}

void Engine::registerObject(Object *object)
{
    this->renderer->registerObject(object);
}