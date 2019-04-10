DEFINES += LITTLE_GRAPHICS_ENGINE
TEMPLATE = lib
TARGET = LEngine
CONFIG += c++14
CONFIG -= qt

DESTDIR = $$PWD/../dist/bin

sdk_engine.path = $$PWD/../dist/include/
sdk_engine.files += engine.h  shared_library.h

sdk_renderer.path = $$PWD/../dist/include/renderer
sdk_renderer.files += renderer/renderer.h

INSTALLS += sdk_engine sdk_renderer

HEADERS += \
    shared_library.h \
    engine.h \
    renderer/renderer.h \
    glad/glad.h \
    glad/KHR/khrplatform.h \
    renderer/shaderprogrammanager.h \
    renderer/buffermanager.h

SOURCES += \
    engine.cpp \
    renderer/renderer.cpp \
    glad.c \
    renderer/shaderprogrammanager.cpp \
    renderer/buffermanager.cpp
