#include "glad/glad.h"
#include "renderer.h"
#include "shaderprogrammanager.h"

#include <iostream>

LENGINE_NAMESPACE_BEGIN

static GLuint vao = 0;

Renderer::Renderer()
    : shaderProgram(new ShaderProgramManager)
{

}

Renderer::~Renderer()
{
    if(shaderProgram) delete shaderProgram;
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

    // glClearColor(0.2f,0.3f,0.4f,1.0f);

    if(!shaderProgram->setupLayered2DPipeline()) {
        std::cout << "setup 2d failed" << std::endl;
        return false;
    }

    GLfloat triangle[]= {
        0.0f,0.0f,
        0.5f,0.0f,
        0.25f,0.5f,
        0.0f,0.0f,
        -0.5f,0.0f,
        -0.25f,0.5f
    };

    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    GLuint buffer = 0;
    glGenBuffers(1,&buffer); // gen unused buffer object names, then mark them as used
    glBindBuffer(GL_ARRAY_BUFFER,buffer); // create buffer object
    // glBufferData(GL_ARRAY_BUFFER,sizeof(triangle),triangle,GL_STATIC_DRAW);
    glBufferStorage(GL_ARRAY_BUFFER,sizeof(triangle),triangle,GL_MAP_WRITE_BIT);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,nullptr);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    return true;
}

void Renderer::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBindVertexArray(vao);
    shaderProgram->drawLayered2D();
    shaderProgram->setLayer(1.0f);
    glDrawArrays(GL_TRIANGLES,0,6);
}

void Renderer::resizeViewport(int w, int h)
{
    glViewport(0,0,w,h);
}

LENGINE_NAMESPACE_END
