#ifndef SCENE_H
#define SCENE_H

#include "shared_library.h"
#include <string>

LENGINE_NAMESPACE_BEGIN

class ENGINE_API Scene
{
public:
    Scene();
    ~Scene();

    void loadScene(const std::string &uri);
};

LENGINE_NAMESPACE_END
#endif // SCENE_H
