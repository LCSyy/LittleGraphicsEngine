#include <QGuiApplication>
#include "window/window.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}
