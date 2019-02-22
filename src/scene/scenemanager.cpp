#include "scenemanager.hpp"
#include <iostream>

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
    if(_rootNode) delete _rootNode;
    _rootNode = nullptr;

    /*
    if(_pMem) {
        delete[] _pMem;
        _pMem = nullptr;
    }
    
    _pCurPtr = nullptr;
    */
}

void SceneManager::init()
{
    /*
    _pMem = new char[1024];
    _pCurPtr = _pMem;
    */
}

void SceneManager::setRoot(SceneNode *node)
{
    if(node) _rootNode = node;
}
