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

void Engine::runGame()
{
    this->renderer->setup();
    this->renderer->render();
    this->renderer->clear();
}