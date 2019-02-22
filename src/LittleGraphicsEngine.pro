TEMPLATE = app
TARGET = LittleGraphicsEngine
CONFIG += c++14
DESTDIR = $$PWD/../build

SOURCES += \
    main.cpp \
    scene/scenemanager.cpp \
    scene/scenenode.cpp \
    engine.cpp

HEADERS += \
    scene/scenemanager.hpp \
    scene/scenenode.hpp \
    engine.hpp

