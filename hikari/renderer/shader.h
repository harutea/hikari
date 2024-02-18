#ifndef SHADER_H
#define SHADER_H

#include <string>

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
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
        unsigned int getID() const;
    };
}

#endif SHADER_H