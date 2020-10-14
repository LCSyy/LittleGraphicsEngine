#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "engine_global.hpp"

class RendererPrivate;
class LITTLE_ENGINE_API Renderer {
public:
    Renderer();
    ~Renderer();
    
    void render_frame();

protected:
    void init();
    void finish();

protected:
    RendererPrivate *p;
};

#endif
