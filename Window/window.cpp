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
    mCamera = new Camera3D(Vector3D(0.0f,0.0f,-1.0f));
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
        float pitch = mCamera->camEuler.x;
        float yaw = mCamera->camEuler.y;
        // float roll = mCamera->camEuler.z;
        float pitchStep = PI/180.0f;
        float yawStep   = pitchStep;
        // float rollStep
        QPoint deltaPos = ev->pos() - mLatestPos;
        if(deltaPos.x() > 0) { // look at right
            yaw -= yawStep;
        } else if(deltaPos.x() < 0) {
            yaw += yawStep;
        }
        if(deltaPos.y() > 0) {
            pitch += pitchStep;
        } else if(deltaPos.y() < 0) {
            pitch -= pitchStep;
        }
        if(pitch > PI/2) pitch = PI/2 - pitchStep;
        else if(pitch < -(PI/2)) pitch = -PI/2 + pitchStep;
        if(yaw > PI/2) yaw = PI/2 - yawStep;
        else if(yaw < -(PI/2)) yaw = -PI/2 + yawStep;

        v.x = std::cos(pitch) * std::cos(yaw);
        v.y = std::sin(pitch);
        v.z = std::cos(pitch) * std::sin(yaw);
        mCamera->setFront(v);
        mCamera->camEuler.x = pitch;
        mCamera->camEuler.y = yaw;
        mCamera->camPos.z = 0;
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

