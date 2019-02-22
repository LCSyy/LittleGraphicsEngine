#include <iostream>
#include "engine.hpp"
#include "scene/scenemanager.hpp"

int main(int argc, char *argv[]) {
    Engine::init();
    Engine::scene().init();
    Engine::finalize();
    return 0;
}
