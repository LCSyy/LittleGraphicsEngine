#ifndef RENDERER_H
#define RENDERER_H

#include "shared_library.h"

LENGINE_NAMESPACE_BEGIN

class ENGINE_API Renderer
{
public:
    Renderer();
    ~Renderer();

    bool init();
};

LENGINE_NAMESPACE_END
#endif // RENDERER_H
