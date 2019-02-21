#include "scenemanager.hpp"
#include <iostream>

SceneManager::SceneManager()
{
    std::cout << "Construct SceneManager\n";
}

SceneManager::~SceneManager()
{
    std::cout << "Destruct SceneManager\n";

    if(_pMem) {
        delete[] _pMem;
        _pMem = nullptr;
    }
    
    _pCurPtr = nullptr;
}

void SceneManager::init()
{
    std::cout << "Init\n";
    
    _pMem = new char[1024];
    _pCurPtr = _pMem;
}
