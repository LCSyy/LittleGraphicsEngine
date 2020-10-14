#ifndef GLOBJECT_HPP
#define GLOBJECT_HPP

#include "glad/glad.h"

class GLObject
{
public:
    GLObject();

    GLuint name() const { return _name; }

protected:
    GLuint _name;
};

#endif
