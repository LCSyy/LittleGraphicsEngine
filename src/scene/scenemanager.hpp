#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    void init();

    template<typename T>
    T *createNode(T *parent);

private:
    char *_pMem{nullptr};
    char *_pCurPtr{nullptr};
};

template<typename T>
T *SceneManager::createNode(T *parent)
{
    T *node = new (_pCurPtr) T(parent);
    return node;
}

#endif
