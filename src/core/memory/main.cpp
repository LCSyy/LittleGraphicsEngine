#include <iostream>
#include "geometry.h"

using namespace std;

int main(int argc, char *argv[]) {
    VertexPool pool;
    float vertices[] = {
        0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,
        1.0f,0.0f,0.0f, 1.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,
        0.0f,1.0f,0.0f, 0.0f,1.0f,0.0f,0.0f, 0.0f,0.0f,
        0.0f,0.0f,1.0f, 0.0f,0.0f,1.0f,0.0f, 0.0f,0.0f
    };

    pool.pushVertices(vertices,4);

    cout << *(pool.objAt(0));
    cout << *(pool.objAt(1));
    cout << *(pool.objAt(2));
    cout << *(pool.objAt(3));

    return 0;
}

// 基础设施、硬件、抽象、复杂应用
// 完全的类型安全，资源安全
// Concepts,modules,static reflection, Constracts, Concurrency, parallelism,heterogenous computing
// graphics engine
