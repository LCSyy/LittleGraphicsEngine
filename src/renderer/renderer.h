#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "shared_library.h"

LENGINE_NAMESPACE_BEGIN

class BufferObject;
class BufferManager;
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
    BufferObject *buffer{nullptr};
    BufferManager *buffers{nullptr};
    ShaderProgramManager *shaderPrograms{nullptr};
};

LENGINE_NAMESPACE_END
#endif // RENDERER_H
