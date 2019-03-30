#include "engine.h"
#include "renderer/renderer.h"

LENGINE_NAMESPACE_BEGIN

Renderer *Engine::_renderer = nullptr;

bool Engine::init()
{
    if(!_renderer) _renderer = new Renderer;
    return true;
}

void Engine::release()
{

}

LENGINE_NAMESPACE_END
