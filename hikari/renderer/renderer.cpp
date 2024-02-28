#include "renderer.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <stb_image.h>

using namespace hikari;
using namespace std;

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::setup()
{
    /* Setup window */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    window = glfwCreateWindow(800, 600, "hikari", NULL, NULL);
    if (window == NULL)
    {
        std::cout << " Failed to create GLFW window" << std::endl;
        glfwTerminate();
        // return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGL(glfwGetProcAddress))
    {
        cout << "Error : Failed to initialize OpenGL context." << endl;
        return;
    };
    // glfwSwapInterval(1);

    glEnable(GL_DEPTH_TEST);

    // Setup all objects in Object Pool
    for (auto itr = objectPool.begin(); itr != objectPool.end(); itr++)
    {
        (*itr)->setup();
    }

    glfwSetFramebufferSizeCallback(window, &Renderer::framebuffer_size_callback);
}

void Renderer::render()
{
    while (!glfwWindowShouldClose(window))
    {
        this->processInput(window);
        glClearColor(0.99f, 0.99f, 0.99f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render all objects in Object Pool
        for (auto itr = objectPool.begin(); itr != objectPool.end(); itr++)
        {
            (*itr)->render();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Renderer::clear()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glfwTerminate();
}

void Renderer::processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void Renderer::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Renderer::putObject(Object *object)
{
    objectPool.push_back(object);
}