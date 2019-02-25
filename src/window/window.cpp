#include "window.h"
#include "engine.hpp"

#include <QFile>
#include <QTextStream>
#include <QMouseEvent>
#include <QWheelEvent>

Window::Window(QWindow *parent)
    : OpenGLWindow(parent)
{
}

Window::~Window()
{
}

void Window::initialize()
{
    _pipeline = new Pipeline;
    _pipeline->draw_mode = GL_TRIANGLES;
    _pipeline->vertex_position_component_size = 3;

    Engine::initialize();
    Engine::graphics().clearColor(0.1f,0.3f,0.5f);
    std::string vsrc{"#version 430 core\nlayout(position=0) vec3 ioPos;\nvoid main(){gl_Position = vec4(ioPos,1,0f);}"}; // loadFile("vertex.glsl");
    std::string fsrc{"#version 430 core\nout vec4 ioColor;\nvoid main() {ioColor = vec4(0.99f,0.99f,0.99f,1.0f);}"}; // loadFile("fragment.glsl");
    Engine::graphics().createShaderProgram(*_pipeline,vsrc.data(),fsrc.data(),nullptr,nullptr,nullptr);

    Engine::graphics().createVertexArray(*_pipeline);

    float rect[12] = {
        -0.5f,-0.5f,0.0f,
        -0.5f, 0.5f,0.0f,
         0.5f, 0.5f,0.0f,
         0.5f,-0.5f,0.0f
    };

    unsigned int cube_indices[6] = {
        0,1,2,
        0,2,3
    };

    Engine::graphics().uploadData(*_pipeline,sizeof(rect),rect,sizeof(cube_indices),cube_indices);
}

void Window::update()
{
    Engine::graphics().update();
    Engine::graphics().drawBegin(*_pipeline);
    // Engine::graphics().setUniformValue(*_pipeline,)
    Engine::graphics().drawEnd(*_pipeline);
}

void Window::frameResize(int w, int h)
{
    Engine::graphics().resize(w,h);
}

void Window::finalize()
{
    Engine::graphics().cleanupGL(*_pipeline);
    Engine::finalize();
}

void Window::mouseMoveEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
}

void Window::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
}

void Window::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
}

void Window::wheelEvent(QWheelEvent *ev)
{
    Q_UNUSED(ev)
}

std::string Window::loadFile(const std::string &file)
{
    QFile f(QString::fromStdString(file));
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return std::string("");
    }
    QTextStream in(&f);
    return in.readAll().toStdString();
}

