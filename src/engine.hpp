#ifndef ENGINE_HPP_
#define ENGINE_HPP_

class SceneManager;

class Engine
{
public:
    static bool init();
    static void finalize();

    static SceneManager &scene();

private:
    static SceneManager *_sceneManager;    
};

#endif
