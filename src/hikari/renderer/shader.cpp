#include "shader.h"
#include <glad/gl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace hikari;
using namespace std;

Shader::Shader()
{
}

Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    string vertexShaderSource;
    string fragmentShaderSource;
    ifstream vertexShaderFile;
    ifstream fragmentShaderFile;

    vertexShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    fragmentShaderFile.exceptions(ifstream::failbit | ifstream::badbit);

    try
    {
        vertexShaderFile.open(vertexShaderPath);
        fragmentShaderFile.open(fragmentShaderPath);
        stringstream vertexShaderStream, fragmentShaderStream;
        vertexShaderStream << vertexShaderFile.rdbuf();
        fragmentShaderStream << fragmentShaderFile.rdbuf();
        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexShaderSource = vertexShaderStream.str();
        fragmentShaderSource = fragmentShaderStream.str();
    }
    catch (ifstream::failure e)
    {
        cout << "Error in Shader : File is not succesfully read." << endl;
    }
    const char *vertShaderRaw = vertexShaderSource.c_str();
    const char *fragShaderRaw = fragmentShaderSource.c_str();

    unsigned int vertexShader, fragmentShader;
    int success;
    char infoLog[512];

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertShaderRaw, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        cout << "Error in Shader : Vertex Shader Compilation Failed\n"
             << infoLog << endl;
    }

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragShaderRaw, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        cout << "Error in Shader : Fragment Shader Compilation Failed\n"
             << infoLog << endl;
    }

    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertexShader);
    glAttachShader(this->ID, fragmentShader);
    glLinkProgram(this->ID);

    glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
        cout << "Error in Shader : Program Link Failed\n"
             << infoLog << endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    glDeleteProgram(this->ID);
}

void Shader::use()
{
    glUseProgram(this->ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
}