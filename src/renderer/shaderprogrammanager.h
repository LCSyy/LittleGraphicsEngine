#ifndef SHADERPROGRAMMANAGER_H
#define SHADERPROGRAMMANAGER_H

#include "glad/glad.h"
#include "shared_library.h"
#include <string>
#include <vector>

LENGINE_NAMESPACE_BEGIN

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

struct ShaderProgramPrivate;

class ShaderProgramManager
{
public:
    ShaderProgramManager();
    ~ShaderProgramManager();

    bool setupLayered2DPipeline();

    void drawLayered2D();
    void setLayer(GLfloat layer);
private:
    GLuint createShader(ShaderType::Shader iShader, const char *src);
    GLuint createProgram();
    void attachShader(GLuint program, GLuint shader);
    void attachShaders(GLuint program, const std::vector<GLuint> &shaders);
    void detachShader(GLuint program, GLuint shader);
    void detachShaders(GLuint program, const std::vector<GLuint> &shaders);
    bool linkProgram(GLuint program);

private:
    ShaderProgramPrivate *d{nullptr};
};

LENGINE_NAMESPACE_END
#endif // SHADERPROGRAMMANAGER_H
