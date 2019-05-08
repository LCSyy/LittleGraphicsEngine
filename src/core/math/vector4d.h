#ifndef VECTOR4D_H
#define VECTOR4D_H

#include "shared_library.h"
#include <cmath>
#include <cfloat>

LENGINE_NAMESPACE_BEGIN
struct Vector4D
{
    Vector4D(): Vector4D(0.0f,0.0f,0.0f,0.0f) {}
    Vector4D(float _x, float _y, float _z, float _w): x(_x),y(_y),z(_z), w(_w){}

    Vector4D operator*(float n) const {
        return Vector4D{x*n,y*n,z*n,w*n};
    }

    friend Vector4D operator*(float n, const Vector4D &v) {
        return v*n;
    }

    Vector4D &operator*=(float n) {
        x *= n; y *= n; z *= n; w *= n;
        return *this;
    }

    Vector4D &operator/(float n) {
        if(std::fabs(n) > FLOAT_PRECISE) {
            x /= n; y /= n; z /= n; w /= n;
        } else {
            x = FLT_MAX; y = FLT_MAX; z = FLT_MAX; w = FLT_MAX;
        }
        return *this;
    }

    Vector4D operator+(const Vector4D &rhs) const {
        return Vector4D{x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w};
    }

    Vector4D &operator+=(const Vector4D &rhs) {
        x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w;
        return *this;
    }

    Vector4D operator-(const Vector4D &rhs) const {
        return Vector4D{x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w};
    }

    Vector4D &operator-=(const Vector4D &rhs) {
        x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w;
        return *this;
    }

    float dot(const Vector4D &rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
    }

    Vector4D normalized() const {
        const float len = length();
        if(len > FLOAT_PRECISE) {
            return Vector4D{x/len,y/len,z/len,w/len};
        }
        return Vector4D{0.0f,0.0f,0.0f,0.0f};
    }

    float length() const {
        return std::sqrt(x*x+y*y+z*z+w*w);
    }

    float x;
    float y;
    float z;
    float w;
};

LENGINE_NAMESPACE_END
#endif // VECTOR4D_H
