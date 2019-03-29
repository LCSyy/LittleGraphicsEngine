#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "graphics/graphicsengine.hpp"
#include "scene/scenemanager.hpp"

class Engine
{
public:
    static bool initialize();
    static void finalize();

    static GraphicsEngine &graphics();
    static SceneManager &scene();

private:
    static GraphicsEngine *_graphicsEngine;
    static SceneManager *_sceneManager;    
};

#endif
