#include "texture.h"

LENGINE_NAMESPACE_BEGIN

Texture::Texture()
{
    glGenTextures(1,&_name);
}

Texture::~Texture()
{
    glDeleteTextures(1,&_name);
}

void Texture::bind()
{
    glBindTexture(target(),_name);
}

void Texture::unbind()
{
    glBindTexture(target(), 0);
}

LENGINE_NAMESPACE_END
