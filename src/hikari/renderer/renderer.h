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
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        float vertices[18] = {
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f};
        unsigned indices[3] = {
            0, 1, 2};
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