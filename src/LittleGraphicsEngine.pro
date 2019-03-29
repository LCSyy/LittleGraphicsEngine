DEFINES += LITTLE_GRAPHICS_ENGINE
TEMPLATE = lib
TARGET = LEngine
CONFIG += c++14

HEADERS += \
    shared_library.h \
    engine.h

DESTDIR = $$PWD/../dist/bin

sdk.path = $$PWD/../dist/include/
sdk.files += $$PWD/*.h

INSTALLS += sdk

SOURCES += \
    engine.cpp
