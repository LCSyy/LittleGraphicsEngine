#include "bufferobject.h"

LENGINE_NAMESPACE_BEGIN

BufferObject::BufferObject()
{
    glGenBuffers(1,&_buffer);
}

BufferObject::~BufferObject()
{
    glDeleteBuffers(1,&_buffer);
}

void BufferObject::bind()
{
    glBindBuffer(target(),_buffer);
}

void BufferObject::unbind()
{
    glBindBuffer(target(),0);
}

GLuint BufferObject::name() const
{
    return _buffer;
}

void BufferObject::bufferData(GLsizeiptr size, const void *data, GLenum usage)
{
    glBufferData(target(),size,data,usage);
}

void BufferObject::bufferSubData(GLintptr offset, GLsizeiptr size, const void *data)
{
    glBufferSubData(target(),offset,size,data);
}

void BufferObject::clearBufferData(GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)
{
    glClearBufferSubData(target(),internalformat,offset,size,format, type, data);
}

void BufferObject::getBufferData(GLintptr offset, GLsizeiptr size, void *data)
{
    glGetBufferSubData(target(),offset,size,data);
}

void *BufferObject::mapBufferRange(GLintptr offset, GLsizeiptr length, GLbitfield access)
{
    return glMapBufferRange(target(),offset,length,access);
}

void BufferObject::unmapBuffer()
{
    glUnmapBuffer(target());
}

ArrayBufferObject::ArrayBufferObject()
    : BufferObject()
{

}

ArrayBufferObject::~ArrayBufferObject()
{

}


LENGINE_NAMESPACE_END
