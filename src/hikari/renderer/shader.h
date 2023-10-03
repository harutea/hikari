#ifndef SHADER_H
#define SHADER_H

namespace hikari
{
    class Shader
    {
    private:
        unsigned int ID;

    public:
        Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
        ~Shader();
        void use();
    };
}

#endif SHADER_H