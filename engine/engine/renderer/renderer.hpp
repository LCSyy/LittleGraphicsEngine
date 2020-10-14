#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>
#include "engine_global.hpp"

class BufferObject;
class BufferManager;
class ShaderProgramManager;
struct Matrix4x4;

class LITTLE_ENGINE_API Renderer
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

#endif
