#ifndef SHADERPROGRAMMANAGER_HPP
#define SHADERPROGRAMMANAGER_HPP

#include "glad/glad.h"
#include "engine_global.hpp"
#include <string>
#include <vector>

struct ShaderType {
    enum Shader {
        VERTEX,
        TESS_CONTROL,
        TESS_EVAL,
        GEOMETRY,
        FRAGMENT,
        COMPUTE
    };
};

class ShaderProgramManager
{
public:
    ShaderProgramManager();
    ~ShaderProgramManager();

    GLuint createShader(ShaderType::Shader iShader, const char *src);
    GLuint createProgram();
    void attachShader(GLuint program, GLuint shader);
    void attachShaders(GLuint program, const std::vector<GLuint> &shaders);
    void detachShader(GLuint program, GLuint shader);
    void detachShaders(GLuint program, const std::vector<GLuint> &shaders);
    bool linkProgram(GLuint program);

    void setFloatValue(GLuint program, const GLchar *name, float data);
    void setMat4Value(GLuint program, const GLchar *name, const GLfloat *data);
};

#endif
