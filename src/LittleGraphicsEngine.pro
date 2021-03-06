DEFINES += LITTLE_GRAPHICS_ENGINE
TEMPLATE = lib
TARGET = LEngine
CONFIG += c++14
CONFIG -= qt

INCLUDEPATH += $$PWD/thirdparty

DESTDIR = $$PWD/../dist/bin

sdk_engine.path = $$PWD/../dist/include/
sdk_engine.files += \
    engine.h \
    shared_library.h

sdk_renderer.path = $$PWD/../dist/include/renderer
sdk_renderer.files += \
    renderer/renderer.h

sdk_core_math.path = $$PWD/../dist/include/core/math
sdk_core_math.files += \
    core/math/matrix4x4.h \
    core/math/point2d.h \
    core/math/point3d.h \
    core/math/vector2d.h \
    core/math/vector3d.h \
    core/math/vector4d.h \
    core/math/transform.h

sdk_scene.path = $$PWD/../dist/include/scene
sdk_scene.files += \
    scene/scene.h \
    scene/camera3d.h

INSTALLS += sdk_engine sdk_renderer sdk_core_math sdk_scene

HEADERS += \
    core/container/allocator.h \
    $${sdk_core_math.files} \
    $${sdk_scene.files} \
    $${sdk_engine.files} \
    $${sdk_renderer.files} \
    renderer/shaderprogrammanager.h \
    renderer/buffermanager.h \
    renderer/bufferobject.h \
    renderer/globject.h \
    renderer/texture.h

SOURCES += \
    core/container/allocator.cpp \
    scene/scene.cpp \
    thirdparty/glad/glad.c \
    engine.cpp \
    renderer/renderer.cpp \
    renderer/shaderprogrammanager.cpp \
    renderer/buffermanager.cpp \
    renderer/bufferobject.cpp \
    renderer/globject.cpp \
    renderer/texture.cpp
