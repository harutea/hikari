#ifndef RENDERER_H
#define RENDERER_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace hikari
{
    class Renderer
    {
    private:
        GLFWwindow *window;
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
        unsigned int vertexShader;
        unsigned int fragmentShader;
        unsigned int shaderProgram;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        float vertices[12] = {
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f};
        unsigned indices[6] = {
            0, 1, 3,
            1, 2, 3};
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