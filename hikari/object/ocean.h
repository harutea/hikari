#ifndef OCEAN_H
#define OCEAN_H

#include <hikari/vector/vector.h>
#include <hikari/renderer/shader.h>
#include "object.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace hikari {
class Ocean : public Object {

public:
  Ocean();
  Ocean(float initX, float initY, float initZ, int OceanSize);
  ~Ocean();
  void setup();
  void render();
  void clear();
  void updateView(glm::mat4 _view);
  void updateProjection(glm::mat4 _projection);
  void updateCameraPosition(glm::vec3 _cameraPosition);

private:
  int OceanSize;
};

} // namespace hikari

#endif