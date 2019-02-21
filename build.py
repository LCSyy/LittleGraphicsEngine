# -*- utf-8 -*-

INCLUDE_PATHS = [
    './src'
]

HEADERS = [
    './src/scene/scenemanager.hpp',
    './src/scene/scenenode.hpp',
    './src/module/module.hpp'
]

SOURCES = [
    './src/main.cpp',
    './src/scene/scenemanager.cpp',
    './src/scene/scenenode.cpp',
    './src/module/module.cpp'
]

COMPILER = 'clang++'

TARGET = 'LittleGraphicsEngine'
