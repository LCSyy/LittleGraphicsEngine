#ifndef CAMERA3D_HPP
#define CAMERA3D_HPP

#include "math/matrix4x4.h"
#include "math/vector3d.h"

struct Camera3D: public Matrix4x4
{
    Camera3D(const Vector3D &_camPos) {
        setRight(Vector3D(-1.0f,0.0f,0.0f));
        setUp(Vector3D(0.0f,1.0f,0.0f));
        setFront(Vector3D(0.0f,0.0f,-1.0f));
        setPos(_camPos);
    }

    void setPos(const Vector3D &_camPos) {
        camPos = _camPos;
        m[12] = -(m[0]*camPos.x+m[4]*camPos.y+m[8]*camPos.z);
        m[13] = -(m[1]*camPos.x+m[5]*camPos.y+m[9]*camPos.z);
        m[14] = -(m[2]*camPos.x+m[6]*camPos.y+m[10]*camPos.z);
    }

    void setRight(const Vector3D &camRight) {
        m[0] = camRight.x;
        m[4] = camRight.y;
        m[8] = camRight.z;
    }

    void setUp(const Vector3D &camUp) {
        m[1] = camUp.x;
        m[5] = camUp.y;
        m[9] = camUp.z;
    }

    void setFront(const Vector3D &camFront) {
        m[2] = camFront.x;
        m[6] = camFront.y;
        m[10] = camFront.z;
    }

    Vector3D camPos;
    // pitch yaw roll
    Vector3D camEuler;
};

// [Rx Ry Rz -(Px*Rx+Py*Ry+Pz*Rz)]
// [Ux Uy Uz -(Px*Ux+Py*Uy+Pz*Uz)]
// [Dx Dy Dz -(Px*Dx+Py*Dy+Pz*Dz)]
// [0  0  0  1]

#endif // CAMERA3D_HPP
