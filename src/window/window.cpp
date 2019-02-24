#include "window.h"
#include "engine.hpp"

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
    Engine::initialize();
}

void Window::update()
{
}

void Window::frameResize()
{
}

void Window::finalize()
{
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
