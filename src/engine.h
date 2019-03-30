#ifndef ENGINE_H
#define ENGINE_H

#include "shared_library.h"

LENGINE_NAMESPACE_BEGIN

class Renderer;

class ENGINE_API Engine
{
public:
    static bool init();
    static void release();

    static Renderer &renderer() { return *_renderer; }

private:
    static Renderer *_renderer;
};

LENGINE_NAMESPACE_END
#endif // ENGINE_H
