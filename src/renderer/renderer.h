#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "shared_library.h"

LENGINE_NAMESPACE_BEGIN

class BufferObject;
class BufferManager;
class ShaderProgramManager;
struct Camera3D;

class ENGINE_API Renderer
{
public:
    Renderer();
    ~Renderer();

    bool init();
    void render();
    void resizeViewport(int w, int h);

    void setCamera(Camera3D *camera);

private:
    BufferObject *buffer{nullptr};
    BufferManager *buffers{nullptr};
    ShaderProgramManager *shaderPrograms{nullptr};
    Camera3D *mCamera{nullptr};
};

LENGINE_NAMESPACE_END
#endif // RENDERER_H
