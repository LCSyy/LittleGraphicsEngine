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

    GLuint m_vert_shader;
    GLuint m_frag_shader;
    GLuint m_shader_program;

    GLfloat m_vertices[3][2] = {
        {0.5f,-0.5f},
        {0.0f,0.5f},
        {-0.5f,-0.5f}
    };
};

const static GLchar* verts = {"#version 430 core\n"
                            "layout(location=0) in vec2 iPos;"
                            "void main() {"
                            "gl_Position = vec4(iPos,0.0f,1.0f);"
                            "}"};
const static GLchar *frag = {"#version 430 core\n"
                            "out vec4 ioFragColor;"
                            "void main() {"
                            "ioFragColor=vec4(0.3f,0.6f,0.4f,1.0f);"
                            "}"};

Renderer::Renderer()
    : p(new RendererPrivate)
{
    p->m_init = false;
}

Renderer::~Renderer() {
    if (p) { delete p; p = nullptr; }
}

void Renderer::render_frame() {
    init();

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.3,0.4,0.5,1.0);

    glUseProgram(p->m_shader_program);
    glBindVertexArray(p->m_vaos[0]);
    glDrawArrays(GL_TRIANGLES,0,3);
    glBindVertexArray(0);
    glUseProgram(0);
}

void Renderer::init() {
    if (p->m_init) { return; }
    p->m_init = true;

    p->m_vao_count = 1;
    p->m_vaos = (GLuint*)(malloc(p->m_vao_count));
    if (!p->m_vaos) { return; }

    p->m_vbo_count = 1;
    p->m_vbos = (GLuint*)(malloc(p->m_vbo_count));
    if (!p->m_vbos) { return; }

    glGenVertexArrays(p->m_vao_count, p->m_vaos);
    glGenBuffers(p->m_vbo_count, p->m_vbos);

    glBindVertexArray(p->m_vaos[0]);
    glBindBuffer(GL_ARRAY_BUFFER,p->m_vbos[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(p->m_vertices), p->m_vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,(void*)(0));
    glEnableVertexAttribArray(0);

    p->m_vert_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(p->m_vert_shader,1,&verts,NULL);
    glCompileShader(p->m_vert_shader);

    p->m_frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(p->m_frag_shader,1,&frag,NULL);
    glCompileShader(p->m_frag_shader);

    p->m_shader_program = glCreateProgram();
    glAttachShader(p->m_shader_program, p->m_vert_shader);
    glAttachShader(p->m_shader_program, p->m_frag_shader);

    glLinkProgram(p->m_shader_program);
}

void Renderer::finish() {

}