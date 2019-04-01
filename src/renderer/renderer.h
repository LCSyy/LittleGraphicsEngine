#ifndef RENDERER_H
#define RENDERER_H

#include "shared_library.h"

LENGINE_NAMESPACE_BEGIN

class ShaderProgramManager;
class ENGINE_API Renderer
{
public:
    Renderer();
    ~Renderer();

    bool init();
    void render();
    void resizeViewport(int w, int h);

private:
    ShaderProgramManager *shaderProgram{nullptr};
};

LENGINE_NAMESPACE_END
#endif // RENDERER_H
