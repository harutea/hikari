#ifndef RENDERER_H
#define RENDERER_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "shader.h"

namespace hikari
{
    class Renderer
    {
    private:
        GLFWwindow *window;
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
        Shader *triangleShader;
        unsigned int texture0;
        unsigned int texture1;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        char *vertexShaderSource;
        char *fragmentShaderSource;

    public:
        Renderer();
        ~Renderer();
        void processInput(GLFWwindow *window);
        void setup();
        void render();
        void clear();
    };

}

#endif RENDERER_H