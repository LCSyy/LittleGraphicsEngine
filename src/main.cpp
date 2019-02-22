#include "engine.hpp"
#include "scene/scenenode.hpp"
#include "scene/scenemanager.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
    Engine::init();
    Engine::scene().init();

    SceneNode *root = Engine::scene().createNode<SceneNode>(nullptr);
    Engine::scene().setRoot(root);
    root->setName("Root");

    SceneNode *rect = Engine::scene().createNode<SceneNode>(root);
    rect->setName("Rect");

    std::cout << root->id() << ":" << root->name() << std::endl;
    std::cout << rect->id() << ":" << rect->name() << std::endl;

    Engine::finalize();
    return 0;
}
