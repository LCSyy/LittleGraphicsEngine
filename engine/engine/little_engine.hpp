#ifndef LITTLE_ENGINE_HPP
#define LITTLE_ENGINE_HPP

#include <string>
#include "engine_global.hpp"

class LittleEnginePrivate;
class LITTLE_ENGINE_API LittleEngine {
public:
    LittleEngine();
    ~LittleEngine();

    int exec();
    
protected:

protected:
    LittleEnginePrivate *p;
};

#endif
