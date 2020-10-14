#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "globject.hpp"

class Texture: public GLObject
{
public:
    Texture();
    virtual ~Texture();

    void bind();
    void unbind();

    // ...

protected:
    virtual GLenum target() const = 0;
};

#endif
