#ifndef ENGINE_H
#define ENGINE_H

#include "shared_library.h"

class ENGINE_API Engine
{
public:
    static bool init();
    static void release();
};

#endif // ENGINE_H
