#ifndef _MODULE_HPP_
#define _MODULE_HPP_

class SceneManager;

class Module
{
public:
    Module();
    ~Module();

    void init();
    
private:
    SceneManager *_scene{nullptr};
};

#endif
