#ifndef SCENE_HPP
#define SCENE_HPP

#include "engine_global.hpp"
#include <string>

class LITTLE_ENGINE_API Scene
{
public:
    Scene();
    ~Scene();

    void loadScene(const std::string &uri);
};

#endif // SCENE_HPP
