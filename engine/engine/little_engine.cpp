#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "little_engine.hpp"
#include <iostream>

class LittleEnginePrivate {
public:
    GLFWwindow *m_glfw_window;
};

LittleEngine::LittleEngine()
    : p(new LittleEnginePrivate)
{

}

LittleEngine::~LittleEngine() {
    if (p) {
        delete p;
        p = nullptr;
    }
}

int LittleEngine::exec() {
    std::cout << "Run ..." << std::endl;
    if (!glfwInit()) {
        return -1;
    }

    std::cout << "create window" << std::endl;
    p->m_glfw_window = glfwCreateWindow(640,480,"Little Engine", NULL, NULL);
    if (!p->m_glfw_window) {
        glfwTerminate();
        return -1;
    }

    std::cout << "make context current" << std::endl;
    glfwMakeContextCurrent(p->m_glfw_window);

    if(!gladLoadGL()) {
        return -1;
    }
    
    std::cout << "loop" << std::endl;
    while (!glfwWindowShouldClose(p->m_glfw_window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glClearColor(0.3,0.4,0.5,1.0);

        glfwSwapBuffers(p->m_glfw_window);

        glfwPollEvents();
    }

    std::cout << "exit ..." << std::endl;
    glfwTerminate();
    return 0;
}

std::string LittleEngine::version() const {
    return LITTLE_ENGINE_TITLE;
}
