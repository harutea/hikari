#include "game_loop.h"

using namespace hikari;

void GameLoop::run() {
    while(this->getRunningState() == this->RUNNING) {
        this->processInput();
        this->update();
        this->render();
    }
}

void GameLoop::processInput() {

}

void GameLoop::update() {

}

void GameLoop::render() {

}

void GameLoop::getRunningState() {

}