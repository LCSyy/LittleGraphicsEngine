#include "glad/glad.h"
#include "renderer.h"

#include <iostream>

LENGINE_NAMESPACE_BEGIN

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

bool Renderer::init()
{
    // const GLubyte *renderer = glGetString(GL_RENDERER);
    // const GLubyte *vendor   = glGetString(GL_VENDOR);
    // const GLubyte *version  = glGetString(GL_VERSION);
    // const GLubyte *shading_language_version = glGetString(GL_SHADING_LANGUAGE_VERSION);
    //
    // std::cout << renderer << std::endl;
    // std::cout << vendor << std::endl;
    // std::cout << version << std::endl;
    // std::cout << shading_language_version << std::endl;

    return true;
}

LENGINE_NAMESPACE_END
