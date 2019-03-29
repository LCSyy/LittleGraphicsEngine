#include "window.h"
#include <QFile>
#include <QTextStream>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>
#include "engine.h"

Window::Window(QWindow *parent)
    : OpenGLWindow(parent)
{
}

Window::~Window()
{
}

void Window::initialize()
{
    if(Engine::init()) {
        qDebug() << "Ok";
    }
}

void Window::update()
{

}

void Window::frameResize(int w, int h)
{
}

void Window::finalize()
{
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

