#include "module.hpp"
#include "scene/scenemanager.hpp"

#include <iostream>

Module::Module()
{
    std::cout << "Construct Module\n";

    _scene = new SceneManager;
}

Module::~Module() 
{
    std::cout << "Destruct Module\n";
    
    if(_scene) delete _scene;

    _scene = nullptr;
}

void Module::init()
{
    _scene->init();
}
