#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include "scenenode.hpp"

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    void init();
    void setRoot(SceneNode *node);

    template<typename T>
    T *createNode(T *parent);

private:
    char *_pMem{nullptr};
    char *_pCurPtr{nullptr};

    SceneNode *_rootNode{nullptr};
};

template<typename T>
T *SceneManager::createNode(T *parent)
{
    // T *node = new (_pCurPtr) T(parent);
    T *node = new T(parent);
    _pCurPtr += sizeof(T);

    if(parent)
        parent->addChild(node);

    return node;
}

#endif
