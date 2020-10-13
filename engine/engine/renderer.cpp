#include "renderer.hpp"
#include "glad/glad.h"
#include <cstdlib>

class RendererPrivate {
public:
    bool m_init;

    GLsizei m_vao_count;
    GLuint* m_vaos;

    GLsizei m_vbo_count;
    GLuint* m_vbos;

    GLfloat m_vertices[3][2] = {
        {0.5f,-0.5f},
        {0.0f,0.5f},
        {-0.5f,-0.5f}
    };
};

Renderer::Renderer()
    : p(new RendererPrivate)
{
    p->m_init = true;
}

Renderer::~Renderer() {
    if (p) { delete p; p = nullptr; }
}

void Renderer::render() {
    if (p->m_init) {
        p->m_vao_count = 1;
        p->m_vaos = (GLuint*)(malloc(p->m_vao_count));
        if (!p->m_vaos) { return; }

        p->m_vbo_count = 1;
        p->m_vbos = (GLuint*)(malloc(p->m_vbo_count));
        if (!p->m_vbos) { return; }

        glGenVertexArrays(p->m_vao_count, p->m_vaos);
        glGenBuffers(p->m_vbo_count, p->m_vbos);

        p->m_init = false;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.3,0.4,0.5,1.0);

    glBindVertexArray(p->m_vaos[0]);
    glBindBuffer(GL_ARRAY_BUFFER,p->m_vbos[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(p->m_vertices), p->m_vertices, GL_STATIC_DRAW);
    // ...
}

