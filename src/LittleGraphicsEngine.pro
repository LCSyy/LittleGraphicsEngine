TEMPLATE = app
TARGET = LittleGraphicsEngine
CONFIG += c++14

#### Qt Window ####
CONFIG += qt
QT += gui
###################

SOURCES += \
    main.cpp \
    scene/scenemanager.cpp \
    scene/scenenode.cpp \
    engine.cpp \
    window/openglwindow.cpp \
    window/window.cpp \
    graphics/graphicsengine.cpp

HEADERS += \
    scene/scenemanager.hpp \
    scene/scenenode.hpp \
    engine.hpp \
    window/openglwindow.h \
    window/window.h \
    graphics/graphicsengine.hpp

RESOURCES += \
    res.qrc
