#ifndef LITTLE_ENGINE_HPP
#define LITTLE_ENGINE_HPP

#include <string>

#define LITTLE_ENGINE_TITLE "Little Engine"

class LittleEnginePrivate;
class LittleEngine {
public:
    LittleEngine();
    ~LittleEngine();

    int exec();
    
    std::string version() const;
protected:
    LittleEnginePrivate *p;
};

#endif