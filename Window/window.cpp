#include "window.h"
#include <cmath>
#include <QFile>
#include <QKeyEvent>
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
    resize(400,400);
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
    mCamera = new Camera3D(Vector3D(0.0f,0.0f,0.0f));
    float rad = 0.0f;
    mCamera->m[0] = std::cos(rad);mCamera->m[4] = -std::sin(rad);mCamera->m[8] = 0.0f;mCamera->m[12] = 0.0f;
    mCamera->m[1] = std::sin(rad);mCamera->m[5] = std::cos(rad);mCamera->m[9] = 0.0f;mCamera->m[13] = 0.0f;
    mCamera->m[2] = 0.0f;mCamera->m[6] = 0.0f;mCamera->m[10] = 1.0f;mCamera->m[14] = 0.0f;
    mCamera->m[3] = 0.0f;mCamera->m[7] = 0.0f;mCamera->m[11] = -2.0f;mCamera->m[15] = 1.0f;
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

void Window::keyPressEvent(QKeyEvent *ev)
{
    Vector3D v(mCamera->camPos);

    float step = 0.1f;
    switch(ev->key()) {
    case Qt::Key_W:
        mCamera->setPos(Vector3D(v.x,v.y+step,v.z));
        break;
    case Qt::Key_S:
        mCamera->setPos(Vector3D(v.x,v.y-step,v.z));
        break;
    case Qt::Key_A:
        mCamera->setPos(Vector3D(v.x-step,v.y,v.z));
        break;
    case Qt::Key_D:
        mCamera->setPos(Vector3D(v.x+step,v.y,v.z));
        break;
    }
}

void Window::mouseMoveEvent(QMouseEvent *ev)
{
    if(mPressed) {
        Vector3D v;
        float yRad = mCamera->camEuler.y;
        float yStep = PI/180.0f;
        QPoint delta = ev->pos() - mLatestPos;
        if(delta.x() > 0) {
            yRad += yStep;
        } else if(delta.x() < 0) {
            yRad -= yStep;
        }

        mCamera->m[0] = std::cos(yRad);
        mCamera->m[8] = -std::sin(yRad);
        mCamera->m[2] = std::sin(yRad);
        mCamera->m[10] = std::cos(yRad);
        mCamera->camEuler.y = yRad;
        mLatestPos = ev->pos();
    }
}

void Window::mousePressEvent(QMouseEvent *ev)
{
    mPressed = true;
    mLatestPos = ev->pos();
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

