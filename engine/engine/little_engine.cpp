#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "little_engine.hpp"
#include <iostream>

#include "renderer.hpp"


class LittleEnginePrivate {
public:
    void init() {
        m_renderer = new Renderer;
    }

    void drop() {
        if (m_renderer) { delete m_renderer; m_renderer = nullptr; }
    }

public:
    GLFWwindow *m_glfw_window;

    Renderer *m_renderer;

};

LittleEngine::LittleEngine()
    : p(new LittleEnginePrivate)
{
    p->init();
}

LittleEngine::~LittleEngine() {
    if (p) {
        p->drop();
        delete p;
        p = nullptr;
    }
}

int LittleEngine::exec() {
    if (!glfwInit()) {
        return -1;
    }

    p->m_glfw_window = glfwCreateWindow(640,480,"Little Engine", NULL, NULL);
    if (!p->m_glfw_window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(p->m_glfw_window);

    if(!gladLoadGL()) {
        return -1;
    }
    
    while (!glfwWindowShouldClose(p->m_glfw_window)) {
        p->m_renderer->render_frame();

        glfwSwapBuffers(p->m_glfw_window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
