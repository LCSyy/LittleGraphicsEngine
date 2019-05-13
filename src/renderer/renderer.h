#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "shared_library.h"

LENGINE_NAMESPACE_BEGIN

class BufferObject;
class BufferManager;
class ShaderProgramManager;
struct Matrix4x4;

class ENGINE_API Renderer
{
public:
    Renderer();
    ~Renderer();

    bool init();
    void render();
    void resizeViewport(int w, int h);

    // pipelines
    void setMVP(Matrix4x4 *model, Matrix4x4 *view, Matrix4x4 *projection);

public:
    float aspect{1.0f};
private:
    BufferObject *buffer{nullptr};
    BufferObject *eleBuffer{nullptr};
    BufferManager *buffers{nullptr};
    ShaderProgramManager *shaderPrograms{nullptr};
    Matrix4x4 *mModel{nullptr};
    Matrix4x4 *mView{nullptr};
    Matrix4x4 *mProjection{nullptr};

};

LENGINE_NAMESPACE_END
#endif // RENDERER_H
