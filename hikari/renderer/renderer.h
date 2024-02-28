#ifndef RENDERER_H
#define RENDERER_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include <hikari/object/object.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace hikari
{
    class Renderer
    {
    private:
        GLFWwindow *window;
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
        // Shader *triangleShader;
        // unsigned int texture0;
        // unsigned int texture1;
        // unsigned int VAO;
        // unsigned int VBO;
        // unsigned int EBO;

        glm::vec3 cameraPos;
        glm::vec3 cameraTarget;
        glm::vec3 cameraDirection;
        glm::vec3 up;
        glm::vec3 cameraRight;
        glm::vec3 cameraFront;
        glm::vec3 cameraUp;
        glm::mat4 view;

        std::vector<Object *> objectPool;

    public:
        Renderer();
        ~Renderer();
        void processInput(GLFWwindow *window);
        void setup();
        void render();
        void clear();
        void registerObject(Object *object);
    };

}

#endif RENDERER_H