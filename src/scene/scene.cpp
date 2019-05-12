#include "scene.h"
#include "thirdparty/fx/gltf.h"
#include <iostream>

LENGINE_NAMESPACE_BEGIN

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::loadScene(const std::string &uri)
{
    fx::gltf::Document sceneDoc =  fx::gltf::LoadFromBinary(uri);
    std::cout << "root node: " << sceneDoc.scene << std::endl;
    std::cout << "node count: " << sceneDoc.nodes.size() << std::endl;
}

LENGINE_NAMESPACE_END
