#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "shared_library.h"

LENGINE_NAMESPACE_BEGIN
struct Matrix4x4
{
    Matrix4x4(){
        m[0] =1.0f; m[1] =0.0f; m[2] =0.0f; m[3] =0.0f;
        m[4] =0.0f; m[5] =1.0f; m[6] =0.0f; m[7] =0.0f;
        m[8] =0.0f; m[9] =0.0f; m[10]=1.0f; m[11]=1.0f;
        m[12]=0.0f; m[13]=0.0f; m[14]=0.0f; m[15]=1.0f;
    }

    float m[16];

};

LENGINE_NAMESPACE_END
#endif // MATRIX4X4_H
