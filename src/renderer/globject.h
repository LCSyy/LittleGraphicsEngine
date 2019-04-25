#ifndef GLOBJECT_H
#define GLOBJECT_H

#include "glad/glad.h"
#include "shared_library.h"

LENGINE_NAMESPACE_BEGIN

class GLObject
{
public:
    GLObject();

    GLuint name() const { return _name; }

protected:
    GLuint _name;
};

LENGINE_NAMESPACE_END
#endif // GLOBJECT_H
