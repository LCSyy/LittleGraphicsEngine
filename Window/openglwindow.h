#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QWindow>

class QOpenGLContext;

class OpenGLWindow: public QWindow
{
    Q_OBJECT
public:
    OpenGLWindow(QWindow *parent=nullptr);
    ~OpenGLWindow() override;

protected:
    virtual void initialize();
    virtual void update();
    virtual void frameResize(int w, int h);
    virtual void finalize();

    void resizeEvent(QResizeEvent *event) override;

private slots:
    void shceduleToQuit();
    void render();

private:
    bool bShouldInitialize{false};
    bool bShouldUpdate{true};
    bool bShouldResizeViewport{true};
    bool bShouldFinalize{false};
    QTimer *mFrameTimer{nullptr};
    QOpenGLContext *mContext{nullptr};
};

#endif // OPENGLWINDOW_H
