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

        glm::vec3 cameraPos;
        glm::vec3 cameraTarget;
        glm::vec3 cameraDirection;
        glm::vec3 up;
        glm::vec3 cameraRight;
        glm::vec3 cameraFront;
        glm::vec3 cameraUp;
        glm::mat4 view;
        float deltaTime;

        std::vector<Object *> objectPool;

        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
        void processInput(GLFWwindow *window);
        void mouse_callback(GLFWwindow *window, double xpos, double ypos);

    public:
        Renderer();
        ~Renderer();
        void setup();
        void render();
        void clear();
        void registerObject(Object *object);
    };

}

#endif RENDERER_H