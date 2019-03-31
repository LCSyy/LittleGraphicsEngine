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
    return true;
}

LENGINE_NAMESPACE_END
