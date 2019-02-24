#ifndef GRAPHICSENGINE_HPP
#define GRAPHICSENGINE_HPP

#include<QOpenGLFunctions_4_3_Core>

class GraphicsEngine: protected QOpenGLFunctions_4_3_Core
{
public:
    GraphicsEngine();
};

#endif // GRAPHICSENGINE_HPP
