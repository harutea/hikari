#ifndef ENGINE_H
#define ENGINE_H

#include <hikari/renderer/renderer.h>
#include <hikari/object/object.h>
#include <memory>

namespace hikari {

class Engine {
private:
  std::unique_ptr<Renderer> renderer;

public:
  Engine();
  ~Engine();
  void init();
  void run();
  void registerObject(Object *object);
};

} // namespace hikari

#endif ENGINE_H