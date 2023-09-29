#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace hikari
{
    class GameLoop
    {
    private:
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }
        void processInput(GLFWwindow *window);
        float vertices[9] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f};

        const char *vertexShaderSource = "#version 330 core\n"
                                         "layout (location = 0) in vec3 aPos;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                         "}\0";
        const char *fragmentShaderSource = "#version 330 core\n"
                                           "out vec4 FragColor;\n"
                                           "\n"
                                           "void main()\n"
                                           "{\n"
                                           "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                           "}\0";

    public:
        void run();
        void update();
        void render();
        void getRunningState();
    };

}
#endif GAME_LOOP_H