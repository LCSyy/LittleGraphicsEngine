#ifndef TEXTURE_H
#define TEXTURE_H

#include "globject.h"

LENGINE_NAMESPACE_BEGIN

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


LENGINE_NAMESPACE_END
#endif // TEXTURE_H
