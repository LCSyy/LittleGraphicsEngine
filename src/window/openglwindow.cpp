#include "openglwindow.h"
#include <QGuiApplication>
#include <QOpenGLContext>
#include <QTimer>

#include <QDebug>

OpenGLWindow::OpenGLWindow(QWindow *parent)
    : QWindow(parent)
{
    setSurfaceType(QSurface::OpenGLSurface);
    connect(qGuiApp,SIGNAL(aboutToQuit()),this,SLOT(shceduleToQuit()));

    mFrameTimer = new QTimer(this);
    mFrameTimer->setInterval(16);
    connect(mFrameTimer,SIGNAL(timeout()),this,SLOT(render()));
    mFrameTimer->start();
}

OpenGLWindow::~OpenGLWindow()
{
}

void OpenGLWindow::initialize()
{
}

void OpenGLWindow::update()
{
}

void OpenGLWindow::frameResize()
{
}

void OpenGLWindow::finalize()
{
}

void OpenGLWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    bShouldResizeViewport = true;
}

void OpenGLWindow::shceduleToQuit()
{
    bShouldInitialize = false;
    bShouldUpdate = false;
    bShouldFinalize = true;
    render();
}

void OpenGLWindow::render()
{
    if(!isExposed() && !bShouldFinalize) return;

    if(!mContext) {
        mContext = new QOpenGLContext(this);
        mContext->setFormat(requestedFormat());
        mContext->create();

        bShouldInitialize = true;
    }
    mContext->makeCurrent(this);

    if(bShouldInitialize) {
        initialize();
        bShouldInitialize = false;
    }

    if(bShouldResizeViewport) {
        frameResize();
        bShouldResizeViewport = false;
    }

    if(bShouldUpdate) {
        update();
    }

    mContext->swapBuffers(this);

    if(bShouldFinalize) {
        finalize();
        bShouldFinalize = false;
    }
}
