#include "engine.h"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace hikari;
using namespace std;

Engine::Engine() { this->renderer = make_unique<Renderer>(); }

Engine::~Engine() {
  glfwTerminate();
  cout << "hikari: destroy Engine." << endl;
}

void Engine::init() {}

void Engine::run() {
  this->renderer->setup();
  this->renderer->render();
  this->renderer->clear();
}

void Engine::registerObject(Object *object) {
  this->renderer->registerObject(object);
}