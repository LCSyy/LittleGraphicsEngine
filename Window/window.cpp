#include "window.h"
#include <cmath>
#include <cstring>
#include <QFile>
#include <QKeyEvent>
#include <QTextStream>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>
#include <QMatrix4x4>
#include "engine.h"
#include "scene/scene.h"
#include "renderer/renderer.h"
#include "core/math/matrix4x4.h"

using namespace LEngine;

Window::Window(QWindow *parent)
    : OpenGLWindow(parent)
{
    resize(400,400);
}

Window::~Window()
{
}

void Window::initialize()
{
    if(!Engine::init()) {
        qDebug() << "Engine init failed!";
        return;
    }

    Engine::renderer().init();
    model.translate(QVector3D(0.0f,0.0f,-10.0f));
    view.lookAt(QVector3D(0.0f,0.0f,0.0f),QVector3D(0.0f,0.0f,-1.0f),QVector3D(0.0f,1.0f,0.0f));
    projection.perspective(45.0f,static_cast<float>(width())/height(),0.1f,100.0f);

    // Scene scene;
    // scene.loadScene("./scene_data.glb");
}

void Window::update()
{
    static Matrix4x4 modelMat;
    static Matrix4x4 viewMat;
    static Matrix4x4 projectionMat;

    model.rotate(3.0f,QVector3D(1.0f,1.0f,1.0f));

    std::memcpy(modelMat.m,model.data(),sizeof(float)*16);
    std::memcpy(viewMat.m,view.data(),sizeof(float)*16);
    std::memcpy(projectionMat.m,projection.data(),sizeof(float)*16);
    Engine::renderer().setMVP(&modelMat,&viewMat, &projectionMat);
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
    Q_UNUSED(ev)

    float step = 0.1f;
    switch(ev->key()) {
    case Qt::Key_W:
        view.translate(0.0f,-step,0.0f);
        break;
    case Qt::Key_S:
        view.translate(0.0f,step,0.0f);
        break;
    case Qt::Key_A:
        view.translate(step,0.0f,0.0f);
        break;
    case Qt::Key_D:
        view.translate(-step,0.0f,0.0f);
        break;
    case Qt::Key_Up:
        view.translate(0.0f,0.0f,step);
        break;
    case Qt::Key_Down:
        view.translate(0.0f,0.0f,-step);
        break;
    }
}

void Window::mouseMoveEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    // if(mPressed) {
    //     Vector3D v;
    //     float yRad = mCamera->camEuler.y;
    //     float yStep = PI/180.0f;
    //     QPoint delta = ev->pos() - mLatestPos;
    //     if(delta.x() > 0) {
    //         yRad += yStep;
    //     } else if(delta.x() < 0) {
    //         yRad -= yStep;
    //     }
    //
    //     mCamera->m[0] = std::cos(yRad);
    //     mCamera->m[8] = -std::sin(yRad);
    //     mCamera->m[2] = std::sin(yRad);
    //     mCamera->m[10] = std::cos(yRad);
    //     mCamera->camEuler.y = yRad;
    //     mLatestPos = ev->pos();
    // }
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
    Q_UNUSED(ev)

    // if(ev->angleDelta().y() > 0) {
    //     if(mCamera->m[11]-2.0f > FLOAT_PRECISE) {
    //         mCamera->m[11] -= 1.0f;
    //     }
    // } else {
    //     if(mCamera->m[11] < 10.0f) {
    //         mCamera->m[11] += 1.0f;
    //     }
    // }
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

