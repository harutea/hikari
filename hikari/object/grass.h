#ifndef GRASS_H
#define GRASS_H

#include <hikari/vector/vector.h>
#include <hikari/renderer/shader.h>
#include "object.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace hikari
{
    class Grass : public Object
    {

    public:
        Grass();
        ~Grass();
        void setup();
        void render();
        void clear();
        void updateView(glm::mat4 _view);
        void updateProjection(glm::mat4 _projection);

    private:
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        unsigned int texture0;
        unsigned int texture1;
        glm::mat4 view;
        glm::mat4 projection;

        Shader *shader;

        Vector3 position;
        Vector3 velocity;
        Vector3 force;
        double mass;
    };

}

#endif