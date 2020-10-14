#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <cmath>
#include <cfloat>

struct Vector3D
{
    Vector3D(): Vector3D(0.0f,0.0f,0.0f) {}
    Vector3D(float _x, float _y, float _z): x(_x),y(_y),z(_z){}

    Vector3D operator*(float n) const {
        return Vector3D{x*n,y*n,z*n};
    }

    friend Vector3D operator*(float n, const Vector3D &v) {
        return v*n;
    }

    Vector3D &operator*=(float n) {
        x *= n; y *= n; z *= n;
        return *this;
    }

    Vector3D &operator/(float n) {
        if(std::fabs(n) > FLOAT_PRECISE) {
            x /= n; y /= n; z /= n;
        } else {
            x = FLT_MAX; y = FLT_MAX; z = FLT_MAX;
        }
        return *this;
    }

    Vector3D operator+(const Vector3D &rhs) const {
        return Vector3D{x + rhs.x, y + rhs.y, z + rhs.z};
    }

    Vector3D &operator+=(const Vector3D &rhs) {
        x += rhs.x; y += rhs.y; z += rhs.z;
        return *this;
    }

    Vector3D operator-(const Vector3D &rhs) const {
        return Vector3D{x - rhs.x, y - rhs.y, z - rhs.z};
    }

    Vector3D &operator-=(const Vector3D &rhs) {
        x -= rhs.x; y -= rhs.y; z -= rhs.z;
        return *this;
    }

    float dot(const Vector3D &rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    Vector3D cross(const Vector3D &rhs) const {
        // [Ax,Ay,Az].cross([Bx,By,Bz]) = [Ay*Bz-Az*By,Az*Bx-Ax*Bz,Ax*By-Ay*Bx]
        return Vector3D(y*rhs.z-z*rhs.y,z*rhs.x-x*rhs.z,x*rhs.y-y*rhs.x);
    }

    Vector3D normalized() const {
        const float len = length();
        if(len > FLOAT_PRECISE) {
            return Vector3D{x/len,y/len,z/len};
        }
        return Vector3D{0.0f,0.0f,0.0f};
    }

    float length() const {
        return std::sqrt(x*x+y*y+z*z);
    }

    float x;
    float y;
    float z;
};

#endif // VECTOR3D_HPP
