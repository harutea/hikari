#ifndef OBJECT_H
#define OBJECT_H

#include <hikari/vector/vector.h>
#include <hikari/renderer/shader.h>

namespace hikari
{
    class Object
    {
    private:
        Vector3 position;
        Vector3 velocity;
        Vector3 force;
        double mass;
        unsigned int texture0;
        unsigned int texture1;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;

        Shader *shader;

    public:
        Object();
        ~Object();
        virtual void setup();
        virtual void render();
    };

}

#endif