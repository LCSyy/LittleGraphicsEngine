#include "engine.hpp"

GraphicsEngine *Engine::_graphicsEngine = nullptr;
SceneManager *Engine::_sceneManager = nullptr;

bool Engine::initialize()
{
    if(!_graphicsEngine) _graphicsEngine = new GraphicsEngine;
    if(!_sceneManager) _sceneManager = new SceneManager;

    return true;
}

void Engine::finalize()
{
    if(_graphicsEngine) delete _graphicsEngine;
    if(_sceneManager) delete _sceneManager;

    _graphicsEngine = nullptr;
    _sceneManager = nullptr;
}

GraphicsEngine &Engine::graphics()
{
    return *_graphicsEngine;
}

SceneManager &Engine::scene()
{
    return *_sceneManager;
}
