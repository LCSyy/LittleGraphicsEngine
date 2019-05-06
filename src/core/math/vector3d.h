#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "shared_library.h"

LENGINE_NAMESPACE_BEGIN

struct Vector3D
{
    Vector3D(): Vector3D(0.0f,0.0f,0.0f) {}
    Vector3D(float _x, float _y, float _z): x(_x),y(_y),z(_z){}

    float x;
    float y;
    float z;
};

LENGINE_NAMESPACE_END

#endif // VECTOR3D_H
