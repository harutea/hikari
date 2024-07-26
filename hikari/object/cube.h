#ifndef CUBE_H
#define CUBE_H

#include <hikari/vector/vector.h>
#include <hikari/renderer/shader.h>
#include "object.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace hikari {
class Cube : public Object {

public:
  Cube();
  Cube(float initX, float initY, float initZ);
  ~Cube();
  void setup();
  void render();
  void clear();
  void updateView(glm::mat4 _view);
  void updateProjection(glm::mat4 _projection);
  void updateCameraPosition(glm::vec3 _cameraPos);
};

} // namespace hikari

#endif