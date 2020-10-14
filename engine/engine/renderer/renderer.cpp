#include "glad/glad.h"
#include "renderer.hpp"
#include "shaderprogrammanager.hpp"
#include "buffermanager.hpp"
#include "bufferobject.hpp"
#include "math/matrix4x4.hpp"

#include <iostream>

static GLuint vao = 0;
static GLuint shaderProgram = 0;

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

static const std::string spatialVertexShaderSrc = {"#version 430 core\n"
                                                   "layout(location=0) in vec3 iPos;\n"
                                                   "uniform float aspect;\n"
                                                   "uniform mat4 model;\n"
                                                   "uniform mat4 view;\n"
                                                   "uniform mat4 projection;\n"
                                                   "void main(){"
                                                   "gl_Position = projection * view * model * vec4(iPos.x,iPos.y*aspect,iPos.z,1.0f);"
                                                   "}"};
static const std::string spatialFragmentShaderSrc = {"#version 430 core\n"
                                                     "out vec4 ioFragColor;"
                                                     "void main(){"
                                                     "ioFragColor = vec4(1.0f,0.2f,0.2f,1.0f);"
                                                     "}"};

Renderer::Renderer()
    : buffers(new BufferManager)
    , shaderPrograms(new ShaderProgramManager)
{

}

Renderer::~Renderer()
{
    if(buffer) delete buffer;
    if(eleBuffer) delete eleBuffer;
    if(buffers) delete buffers;
    if(shaderPrograms) delete shaderPrograms;
}

bool Renderer::init()
{
    if(!gladLoadGL()) { return false; }

    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *vendor   = glGetString(GL_VENDOR);
    const GLubyte *version  = glGetString(GL_VERSION);
    const GLubyte *shading_lang_version = glGetString(GL_SHADING_LANGUAGE_VERSION);
    if(!renderer || !vendor || !version || !shading_lang_version) {
        std::cout << "gl init error!" << std::endl;
        return false;
    }

    // init gl extension
    glEnable(GL_DEPTH);

    GLuint vertShader = shaderPrograms->createShader(ShaderType::VERTEX,spatialVertexShaderSrc.c_str());
    GLuint fragShader = shaderPrograms->createShader(ShaderType::FRAGMENT,spatialFragmentShaderSrc.c_str());
    shaderProgram = shaderPrograms->createProgram();
    shaderPrograms->attachShaders(shaderProgram,std::vector<GLuint>({vertShader,fragShader}));
    if(!shaderPrograms->linkProgram(shaderProgram)) {
        std::cerr << "setup 3d failed!" << std::endl;
    }

    GLfloat cube[]= {
        0.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,
        0.0f,0.0f,1.0f,
    };

    GLuint indices[] = {
        0,1,0,2,0,3
    };

    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    buffer = new ArrayBufferObject;
    buffer->bind();
    buffer->bufferData(sizeof(cube),cube,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,nullptr);

    eleBuffer = new ElementBufferObject;
    eleBuffer->bind();
    eleBuffer->bufferData(sizeof(indices),indices,GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    buffer->unbind();
    return true;
}

void Renderer::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(vao);
    glUseProgram(shaderProgram);
    if(mModel) {
        shaderPrograms->setMat4Value(shaderProgram,"model",mModel->m);
    }
    if(mView) {
        shaderPrograms->setMat4Value(shaderProgram,"view",mView->m);
    }
    if(mProjection) {
        shaderPrograms->setMat4Value(shaderProgram,"projection",mProjection->m);
    }
    shaderPrograms->setFloatValue(shaderProgram,"aspect",aspect);

    // glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    // glDrawArrays(GL_TRIANGLES,0,3);
    glDrawElements(GL_LINES,6,GL_UNSIGNED_INT,nullptr);
}

void Renderer::resizeViewport(int w, int h)
{
    glViewport(0,0,w,h);
}

void Renderer::setMVP(Matrix4x4 *model, Matrix4x4 *view, Matrix4x4 *projection)
{
    mModel = model;
    mView = view;
    mProjection = projection;
}
