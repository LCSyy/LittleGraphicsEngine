#include <QGuiApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    Window window;
    window.show();
    return a.exec();
}
