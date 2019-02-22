# -*- utf-8 -*-

INCLUDE_PATHS = [
    './src'
]

HEADERS = [
    './src/engine.hpp',
    './src/scene/scenemanager.hpp',
    './src/scene/scenenode.hpp'
]

SOURCES = [
    './src/main.cpp',
    './src/engine.cpp',
    './src/scene/scenemanager.cpp',
    './src/scene/scenenode.cpp'
]

COMPILER = 'clang++'

# this is c++ language default standard
CXX_STD = 'c++14'

TARGET = 'LittleGraphicsEngine'

OUTPUT_DIR = './build'
