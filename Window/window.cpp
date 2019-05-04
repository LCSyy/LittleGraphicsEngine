#include "window.h"
#include <QFile>
#include <QTextStream>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>
#include "engine.h"
#include "renderer/renderer.h"
#include "scene/camera3d.h"

using namespace LEngine;

Window::Window(QWindow *parent)
    : OpenGLWindow(parent)
{
}

Window::~Window()
{
    if(mCamera) delete mCamera;
}

void Window::initialize()
{
    if(!Engine::init()) {
        qDebug() << "Engine init failed!";
        return;
    }

    Engine::renderer().init();
    mCamera = new Camera3D;
    Engine::renderer().setCamera(mCamera);
}

void Window::update()
{
    Engine::renderer().render();
}

void Window::frameResize(int w, int h)
{
    Engine::renderer().resizeViewport(w,h);
}

void Window::finalize()
{
}

void Window::mouseMoveEvent(QMouseEvent *ev)
{
    if(mPressed) {
        QPoint deltaPos = ev->pos() - mLatestPoint;
        mCamera->m[12] += deltaPos.x() * -0.001f;
        mCamera->m[13] += deltaPos.y() * 0.001f;
        mLatestPoint = ev->pos();
    }
}

void Window::mousePressEvent(QMouseEvent *ev)
{
    mPressed = true;
    mLatestPoint = ev->pos();
}

void Window::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    mPressed = false;
}

void Window::wheelEvent(QWheelEvent *ev)
{
    if(ev->angleDelta().y() > 0) {
        if(mCamera->m[11]-2.0f > FLOAT_PRECISE) {
            mCamera->m[11] -= 1.0f;
        }
    } else {
        if(mCamera->m[11] < 10.0f) {
            mCamera->m[11] += 1.0f;
        }
    }
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

