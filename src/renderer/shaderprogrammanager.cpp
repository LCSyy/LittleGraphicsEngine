#include "shaderprogrammanager.h"

#include <iostream>
#include <cstring>
#include <string>

LENGINE_NAMESPACE_BEGIN

static const std::string layered2DVertexShaderSrc = {"#version 430 core\n"
                                         "layout(location=0) in vec2 iPos;"
                                         "uniform float layer;"
                                         "void main() {"
                                         "gl_Position = vec4(iPos,layer,1.0f);"
                                         "}"};
static const std::string layered2DFragmentShaderSrc = {"#version 430 core\n"
                                        "out vec4 ioFragColor;"
                                        "void main() {"
                                        "ioFragColor=vec4(0.3f,0.6f,0.4f,1.0f);"
                                        "}"};

struct ShaderProgramPrivate
{
    ShaderProgramPrivate() {}

    GLuint layered2DProgram{0};
private:
    DISABLE_COPY(ShaderProgramPrivate)
};

/*!
 * \class ShaderProgramManager
 * \brief ShaderProgramManager类用于生成、管理、销毁shader和program对象。
 *
 * \b{Shader}声明了数据在OpenGL的处理管线可编程阶段移动时，发生的操作。其过程从
 * 应用声明顶点数据到图元最终写入到framebuffer之前的阶段。
 *
 * 要使用一个着色器对象，首先需要加载着色器源码到着色器对象中，然后编译该源码。一个着色器
 * 对应渲染管线中一个可编程阶段，这个阶段被称为着色器阶段或者着色器类型。
 *
 * 如果获取到的NUM_SHADER_BINARY_FORMATS值大于零，即OpenGL支持加载着色器二进制
 * 源码，则还可以直接将预编译的着色器二进制源码加载到着色器对象中。
 *
 * 一个或者多个着色器首先关联到程序对象，然后程序对象连接，生成可执行代码。同样也可以直接
 * 加载使用预编译的程序对象中。
 *
 * 当程序对象绑定到着色器阶段后，这些程序对象就变为该着色器阶段的当前程序对象。当该绑定的程序
 * 对象中包含该类型的着色器对象时，这个程序对象就被称为这个着色器阶段的激活程序对象。
 *
 * 所有着色器阶段的当前程序可以通过一个程序对象一次性统一设置，或者每个阶段使用可分离程序对象
 * 单独设置。不同阶段可以会用不同的可分离程序作为其当前程序。这些作为当前程序的可分离着色器程序
 * 必须绑定到一个程序管线对象上。当一个程序作为一个阶段的激活程序对象后，该阶段就可以执行程序中
 * 链接的对应阶段着色器代码了。
 *
 * 着色器阶段包括：顶点着色器、细分控制着色器、细分计算着色器、几何着色器、片元着色器和计算着色器。
 * 顶点着色器在顶点属性上执行操作。
 * 细分控制和细分计算着色器用于控制细分器(tesselator)的操作。
 * 几何着色器影响顶点到片元的组装过程。
 * 片元着色器影响片元的光栅化过程。
 * 一个程序对象可以包含以上全部或者部分着实色漆。
 *
 * 计算着色器执行通用计算目的。
 *
 * 着色器在执行过程中，可以使用多种类型的变量。
 * 同一变量是每个程序所拥有的。在程序执行过程中对着色器阶段来说是常量。
 * 缓存变量与同一变量类似，但是是存储在可写入的缓存对象中的，且在多个着色器调用过程中一致存在。
 * 子程序同一变量与同一变量类似，但是其与上下文状态有关。
 * 采样器变量一种用于纹理的特殊统一变量。
 * Image是另一种用于特定级别纹理的特殊形式的同一变量。可以通过内建的着色器函数进行访问。
 * 输出变量管理着色器执行的返回结果，它可作为管线下一阶段的输入。
 */
ShaderProgramManager::ShaderProgramManager()
    : d(new ShaderProgramPrivate)
{

}

ShaderProgramManager::~ShaderProgramManager()
{
    if(d) delete d;
    d = nullptr;
}

bool ShaderProgramManager::setupLayered2DPipeline()
{
    GLuint vertShader = createShader(ShaderType::VERTEX,layered2DVertexShaderSrc.c_str());
    GLuint fragShader = createShader(ShaderType::FRAGMENT,layered2DFragmentShaderSrc.c_str());
    d->layered2DProgram = createProgram();
    attachShaders(d->layered2DProgram,std::vector<GLuint>({vertShader,fragShader}));
    if(!linkProgram(d->layered2DProgram))
        return false;
    return true;
}

void ShaderProgramManager::drawLayered2D()
{
    glUseProgram(d->layered2DProgram);
}

void ShaderProgramManager::setLayer(GLfloat layer)
{
    GLint loc = glGetUniformLocation(d->layered2DProgram,"layer");
    glUniform1f(loc,layer);
}

GLuint ShaderProgramManager::createShader(ShaderType::Shader iShader, const char *src)
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
    case ShaderType::FRAGMENT: shaderType = GL_FRAGMENT_SHADER;
        break;
    case ShaderType::COMPUTE: shaderType = GL_COMPUTE_SHADER;
        break;
    }

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader,1,&src,nullptr);
    glCompileShader(shader);
    GLint status = 0;
    glGetShaderiv(shader,GL_COMPILE_STATUS,&status);
    if(status != GL_TRUE) {
        GLint length = 0;
        glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&length);
        char *infoLog = new char[static_cast<size_t>(length) + 1];
        std::memset(infoLog,0,static_cast<size_t>(length) + 1);
        glGetShaderInfoLog(shader,length+1,nullptr,infoLog);
        std::cout << infoLog << std::endl;
        delete[] infoLog;
        return 0;
    }
    return shader;
}

GLuint ShaderProgramManager::createProgram()
{
    return glCreateProgram();
}

void ShaderProgramManager::attachShader(GLuint program, GLuint shader)
{
    glAttachShader(program,shader);
}

void ShaderProgramManager::attachShaders(GLuint program, const std::vector<GLuint> &shaders)
{
    for(GLuint shader: shaders) {
        glAttachShader(program,shader);
    }
}

void ShaderProgramManager::detachShader(GLuint program, GLuint shader)
{
    glDetachShader(program,shader);
}

void ShaderProgramManager::detachShaders(GLuint program, const std::vector<GLuint> &shaders)
{
    for(GLuint shader: shaders) {
        glDetachShader(program,shader);
    }
}

bool ShaderProgramManager::linkProgram(GLuint program)
{
    glLinkProgram(program);
    GLint status = 0;
    glGetProgramiv(program,GL_LINK_STATUS,&status);
    if(status != GL_TRUE) {
        GLsizei length;
        glGetProgramiv(program,GL_INFO_LOG_LENGTH,&length);
        char *infoLog = new char[static_cast<size_t>(length)+1];
        glGetProgramInfoLog(program,length+1,nullptr,infoLog);
        std::cout << infoLog << std::endl;
        delete[] infoLog;
        return false;
    }
    return true;
}

LENGINE_NAMESPACE_END
