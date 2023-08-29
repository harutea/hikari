#include "engine.h"

using namespace hikari;

Engine::Engine() {
    gameLoop = new GameLoop;
}

Engine::~Engine() {
    delete gameLoop;
}

void Engine::runGame() {
    this->gameLoop->run();
}