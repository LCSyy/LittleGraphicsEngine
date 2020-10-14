#include "texture.hpp"

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
