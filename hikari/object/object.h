#ifndef OBJECT_H
#define OBJECT_H

#include <hikari/vector/vector.h>
#include <hikari/renderer/shader.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace hikari
{
    class Object
    {
    public:
        Object();
        ~Object();
        virtual void setup() = 0;
        virtual void render() = 0;
        virtual void clear() = 0;
        virtual void updateView(glm::mat4 _view) = 0;

    private:
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        unsigned int texture0;
        unsigned int texture1;
        glm::mat4 view;

        Vector3 position;
        Vector3 velocity;
        Vector3 force;
        double mass;

        Shader *shader;
    };

}

#endif