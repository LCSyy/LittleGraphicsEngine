#include "engine.hpp"
#include "scene/scenemanager.hpp"

SceneManager *Engine::_sceneManager = nullptr;

bool Engine::init()
{
    if(!_sceneManager) _sceneManager = new SceneManager;

    return true;
}

void Engine::finalize()
{
    if(_sceneManager) delete _sceneManager;

    _sceneManager = nullptr;
}

SceneManager &Engine::scene()
{
    return *_sceneManager;
}