#include "glad/glad.h"
#include "shaderprogrammanager.h"

LENGINE_NAMESPACE_BEGIN

ShaderProgramManager::ShaderProgramManager()
{

}

bool ShaderProgramManager::createShader(LEngine::ShaderType::Shader iShader, const std::string &src)
{
    GLuint shaderType = 0;

    switch (iShader) {
    case ShaderType::VERTEX: shaderType = GL_VERTEX_SHADER;
        break;
    case ShaderType::TESS_CONTROL: shaderType = GL_TESS_CONTROL_SHADER;
        break;
    case ShaderType::TESS_EVAL: shaderType = GL_TESS_EVALUATION_SHADER;
        break;
    case ShaderType::GEOMETRY: shaderType = GL_GEOMETRY_SHADER;
        break;
    case ShaderType::FRAGMENT: shaderType = GL_GEOMETRY_SHADER;
        break;
    }

    const char *srcData = src.c_str();
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader,1,&srcData,nullptr);
    glCompileShader(shader);
}

LENGINE_NAMESPACE_END
