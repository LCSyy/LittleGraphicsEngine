#ifndef BUFFEROBJECT_H
#define BUFFEROBJECT_H

#include "globject.h"

LENGINE_NAMESPACE_BEGIN

class BufferObject: public GLObject
{
public:
    BufferObject();
    virtual ~BufferObject();

    void bind();
    void unbind();

    void bufferData(GLsizeiptr size, const void *data, GLenum usage);
    void bufferSubData(GLintptr offset, GLsizeiptr size, const void *data);
    void clearBufferData(GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);

    void getBufferData(GLintptr offset, GLsizeiptr size, void *data);

    void *mapBufferRange(GLintptr offset, GLsizeiptr length, GLbitfield access);
    void unmapBuffer();

protected:
    virtual GLenum target() const = 0;
};

class ArrayBufferObject: public BufferObject
{
public:
    ArrayBufferObject();
    ~ArrayBufferObject() override;

protected:
    GLenum target() const override { return GL_ARRAY_BUFFER; }
};

LENGINE_NAMESPACE_END
#endif // BUFFEROBJECT_H
