#ifndef WINDOW_H
#define WINDOW_H

#include "openglwindow.h"

// class Camera;

class Window: public OpenGLWindow
{
    Q_OBJECT
public:
    Window(QWindow *parent=nullptr);
    ~Window() override;

protected:
    void initialize() override;
    void update() override;
    void frameResize() override;
    void finalize() override;

    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void wheelEvent(QWheelEvent *ev) override;

private:
    // Camera *mCamera{nullptr};
    // QPoint mLatestPos{QPoint(-1,-1)};
    // bool mPressed{false};
};

#endif // WINDOW_H
