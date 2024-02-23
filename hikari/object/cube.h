#ifndef CUBE_H
#define CUBE_H

#include <hikari/vector/vector.h>
#include <hikari/renderer/shader.h>
#include <vector>

namespace hikari
{
    class Cube : public Object
    {
    private:
        Vector3 position;
        Vector3 velocity;
        Vector3 force;
        double mass;
        unsigned int texture0;
        unsigned int texture1;

        std::vector<float> vertices;

        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;

        Shader *shader;

    public:
        Cube();
        ~Cube();
        void init();
        void render();
    };

}

#endif