#ifndef MATRIX4X4_HPP
#define MATRIX4X4_HPP

#include "vector4d.hpp"

struct Matrix4x4
{
    Matrix4x4(){
        m[0] =1.0f; m[1] =0.0f; m[2] =0.0f; m[3] =0.0f;
        m[4] =0.0f; m[5] =1.0f; m[6] =0.0f; m[7] =0.0f;
        m[8] =0.0f; m[9] =0.0f; m[10]=1.0f; m[11]=0.0f;
        m[12]=0.0f; m[13]=0.0f; m[14]=0.0f; m[15]=1.0f;
    }

    Matrix4x4 operator+(float n) const {
        Matrix4x4 mat;
        for(int i = 0; i < 16; ++i) {
            mat.m[i] = this->m[i] + n;
        }
        return mat;
    }

    Matrix4x4 &operator+=(float n) {
        for (float &e: m) {
            e += n;
        }
        return *this;
    }

    Matrix4x4 operator-(float n) const {
        return (*this)+(-n);
    }

    Matrix4x4 &operator-=(float n) {
        (*this) += (-n);
        return *this;
    }

    Matrix4x4 operator*(float n) const {
        Matrix4x4 mat;
        for(int i = 0; i < 16; ++i) {
            mat.m[i] = this->m[i] * n;
        }
        return mat;
    }

    friend Matrix4x4 operator*(float n, const Matrix4x4 &rhs) {
        return rhs*n;
    }

    Matrix4x4 &operator*=(float n) {
        for(float &e: m) {
            e *= n;
        }
        return *this;
    }

    Matrix4x4 operator+(const Matrix4x4 &rhs) const {
        Matrix4x4 mat;
        for(int i = 0; i < 16; ++i) {
            mat.m[i] = this->m[i] + rhs.m[i];
        }
        return mat;
    }

    Matrix4x4 &operator+=(const Matrix4x4 &rhs) {
        for(int i = 0; i < 16; ++i) {
            m[i] += rhs.m[i];
        }
        return *this;
    }

    Matrix4x4 operator-(const Matrix4x4 &rhs) const {
        return (*this)+((-1)*rhs);

    }

    Matrix4x4 &operator-=(const Matrix4x4 &rhs) {
        (*this)+=((-1)*rhs);
        return *this;
    }

    Matrix4x4 operator*(const Matrix4x4 &rhs) const {
        Matrix4x4 mat;
        mat.m[0] = m[0]*rhs.m[0] + m[1]*rhs.m[4] + m[2]*rhs.m[8]  + m[3]*rhs.m[12];
        mat.m[1] = m[0]*rhs.m[1] + m[1]*rhs.m[5] + m[2]*rhs.m[9]  + m[3]*rhs.m[13];
        mat.m[2] = m[0]*rhs.m[2] + m[1]*rhs.m[6] + m[2]*rhs.m[10] + m[3]*rhs.m[14];
        mat.m[3] = m[0]*rhs.m[3] + m[1]*rhs.m[7] + m[2]*rhs.m[11] + m[3]*rhs.m[15];

        mat.m[4] = m[4]*rhs.m[0] + m[5]*rhs.m[4] + m[6]*rhs.m[8]  + m[7]*rhs.m[12];
        mat.m[5] = m[4]*rhs.m[1] + m[5]*rhs.m[5] + m[6]*rhs.m[9]  + m[7]*rhs.m[13];
        mat.m[6] = m[4]*rhs.m[2] + m[5]*rhs.m[6] + m[6]*rhs.m[10] + m[7]*rhs.m[14];
        mat.m[7] = m[4]*rhs.m[3] + m[5]*rhs.m[7] + m[6]*rhs.m[11] + m[7]*rhs.m[15];

        mat.m[8]  = m[8]*rhs.m[0] + m[9]*rhs.m[4] + m[10]*rhs.m[8]  + m[11]*rhs.m[12];
        mat.m[9]  = m[8]*rhs.m[1] + m[9]*rhs.m[5] + m[10]*rhs.m[9]  + m[11]*rhs.m[13];
        mat.m[10] = m[8]*rhs.m[2] + m[9]*rhs.m[6] + m[10]*rhs.m[10] + m[11]*rhs.m[14];
        mat.m[11] = m[8]*rhs.m[3] + m[9]*rhs.m[7] + m[10]*rhs.m[11] + m[11]*rhs.m[15];

        mat.m[12] = m[12]*rhs.m[0] + m[13]*rhs.m[4] + m[14]*rhs.m[8]  + m[15]*rhs.m[12];
        mat.m[13] = m[12]*rhs.m[1] + m[13]*rhs.m[5] + m[14]*rhs.m[9]  + m[15]*rhs.m[13];
        mat.m[14] = m[12]*rhs.m[2] + m[13]*rhs.m[6] + m[14]*rhs.m[10] + m[15]*rhs.m[14];
        mat.m[15] = m[12]*rhs.m[3] + m[13]*rhs.m[7] + m[14]*rhs.m[11] + m[15]*rhs.m[15];

        return mat;
    }

    Matrix4x4 &operator*=(const Matrix4x4 &rhs) {
        m[0] = m[0]*rhs.m[0] + m[1]*rhs.m[4] + m[2]*rhs.m[8]  + m[3]*rhs.m[12];
        m[1] = m[0]*rhs.m[1] + m[1]*rhs.m[5] + m[2]*rhs.m[9]  + m[3]*rhs.m[13];
        m[2] = m[0]*rhs.m[2] + m[1]*rhs.m[6] + m[2]*rhs.m[10] + m[3]*rhs.m[14];
        m[3] = m[0]*rhs.m[3] + m[1]*rhs.m[7] + m[2]*rhs.m[11] + m[3]*rhs.m[15];

        m[4] = m[4]*rhs.m[0] + m[5]*rhs.m[4] + m[6]*rhs.m[8]  + m[7]*rhs.m[12];
        m[5] = m[4]*rhs.m[1] + m[5]*rhs.m[5] + m[6]*rhs.m[9]  + m[7]*rhs.m[13];
        m[6] = m[4]*rhs.m[2] + m[5]*rhs.m[6] + m[6]*rhs.m[10] + m[7]*rhs.m[14];
        m[7] = m[4]*rhs.m[3] + m[5]*rhs.m[7] + m[6]*rhs.m[11] + m[7]*rhs.m[15];

        m[8]  = m[8]*rhs.m[0] + m[9]*rhs.m[4] + m[10]*rhs.m[8]  + m[11]*rhs.m[12];
        m[9]  = m[8]*rhs.m[1] + m[9]*rhs.m[5] + m[10]*rhs.m[9]  + m[11]*rhs.m[13];
        m[10] = m[8]*rhs.m[2] + m[9]*rhs.m[6] + m[10]*rhs.m[10] + m[11]*rhs.m[14];
        m[11] = m[8]*rhs.m[3] + m[9]*rhs.m[7] + m[10]*rhs.m[11] + m[11]*rhs.m[15];

        m[12] = m[12]*rhs.m[0] + m[13]*rhs.m[4] + m[14]*rhs.m[8]  + m[15]*rhs.m[12];
        m[13] = m[12]*rhs.m[1] + m[13]*rhs.m[5] + m[14]*rhs.m[9]  + m[15]*rhs.m[13];
        m[14] = m[12]*rhs.m[2] + m[13]*rhs.m[6] + m[14]*rhs.m[10] + m[15]*rhs.m[14];
        m[15] = m[12]*rhs.m[3] + m[13]*rhs.m[7] + m[14]*rhs.m[11] + m[15]*rhs.m[15];

        return *this;
    }

    Vector4D operator*(const Vector4D &rhs) const {
        Vector4D vec;
        vec.x = m[0]*rhs.x + m[1]*rhs.y + m[2]*rhs.z  + m[3]*rhs.w;
        vec.y = m[4]*rhs.x + m[5]*rhs.y + m[6]*rhs.z  + m[7]*rhs.w;
        vec.z = m[8]*rhs.x + m[9]*rhs.y + m[10]*rhs.z  + m[11]*rhs.w;
        vec.w = m[12]*rhs.x + m[13]*rhs.y + m[14]*rhs.z  + m[15]*rhs.w;
        return vec;
    }

    friend Vector4D operator*(const Vector4D &lhs, const Matrix4x4 &rhs) {
        Vector4D vec;
        vec.x = lhs.x*rhs.m[0] + lhs.y*rhs.m[4] + lhs.z*rhs.m[8] + lhs.w*rhs.m[12];
        vec.y = lhs.x*rhs.m[1] + lhs.y*rhs.m[5] + lhs.z*rhs.m[9] + lhs.w*rhs.m[13];
        vec.z = lhs.x*rhs.m[2] + lhs.y*rhs.m[6] + lhs.z*rhs.m[10] + lhs.w*rhs.m[14];
        vec.w = lhs.x*rhs.m[3] + lhs.y*rhs.m[7] + lhs.z*rhs.m[11] + lhs.w*rhs.m[15];
        return vec;
    }

    Matrix4x4 normalized() const {
        return Matrix4x4();
    }

    Matrix4x4 transposed() const {
        Matrix4x4 mat;
        mat.m[0] =m[0]; mat.m[1] =m[4]; mat.m[2] =m[8]; mat.m[3] =m[12];
        mat.m[4] =m[1]; mat.m[5] =m[5]; mat.m[6] =m[9]; mat.m[7] =m[13];
        mat.m[8] =m[2]; mat.m[9] =m[6]; mat.m[10]=m[10]; mat.m[11]=m[14];
        mat.m[12]=m[3]; mat.m[13]=m[7]; mat.m[14]=m[11]; mat.m[15]=m[15];
        return mat;
    }

    float m[16];
};

#endif // MATRIX4X4_HPP
