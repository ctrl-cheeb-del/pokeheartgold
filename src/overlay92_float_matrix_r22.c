#include "global.h"

typedef struct Float4 {
    float x;
    float y;
    float z;
    float w;
} Float4;

typedef struct FloatMtx44 {
    float m[4][4];
} FloatMtx44;

void ov92_022634F8(const FloatMtx44 *src, MtxFx44 *dst);
void ov92_022632E8(FloatMtx44 *dst, const Float4 *q);

#define FLOAT_TO_FX(value) ((int)((value) > 0.0f ? (value) * 4096.0f + 0.5f : (value) * 4096.0f - 0.5f))

void ov92_022632E8(FloatMtx44 *dst, const Float4 *q) {
    float xx = (float)((double)(q->y * q->y) * 2.0);
    float yy = (float)((double)(q->z * q->z) * 2.0);
    float zz = (float)((double)(q->w * q->w) * 2.0);
    float xy = (float)((double)(q->y * q->z) * 2.0);
    float yz = (float)((double)(q->z * q->w) * 2.0);
    float zx = (float)((double)(q->w * q->y) * 2.0);
    float xw = (float)((double)(q->y * q->x) * 2.0);
    float yw = (float)((double)(q->z * q->x) * 2.0);
    float zw = (float)((double)(q->w * q->x) * 2.0);

    dst->m[0][0] = (float)((1.0 - (double)yy) - (double)zz);
    dst->m[0][1] = xy + zw;
    dst->m[0][2] = zx - yw;
    dst->m[0][3] = 0.0f;
    dst->m[1][0] = xy - zw;
    dst->m[1][1] = (float)((1.0 - (double)zz) - (double)xx);
    dst->m[1][2] = yz + xw;
    dst->m[1][3] = 0.0f;
    dst->m[2][0] = zx + yw;
    dst->m[2][1] = yz - xw;
    dst->m[2][2] = (float)((1.0 - (double)xx) - (double)yy);
    dst->m[2][3] = 0.0f;
    dst->m[3][0] = 0.0f;
    dst->m[3][1] = 0.0f;
    dst->m[3][2] = 0.0f;
    dst->m[3][3] = 1.0f;
}

void ov92_022634F8(const FloatMtx44 *src, MtxFx44 *dst) {
    dst->_00 = FLOAT_TO_FX(src->m[0][0]);
    dst->_01 = FLOAT_TO_FX(src->m[0][1]);
    dst->_02 = FLOAT_TO_FX(src->m[0][2]);
    dst->_03 = FLOAT_TO_FX(src->m[0][3]);
    dst->_10 = FLOAT_TO_FX(src->m[1][0]);
    dst->_11 = FLOAT_TO_FX(src->m[1][1]);
    dst->_12 = FLOAT_TO_FX(src->m[1][2]);
    dst->_13 = FLOAT_TO_FX(src->m[1][3]);
    dst->_20 = FLOAT_TO_FX(src->m[2][0]);
    dst->_21 = FLOAT_TO_FX(src->m[2][1]);
    dst->_22 = FLOAT_TO_FX(src->m[2][2]);
    dst->_23 = FLOAT_TO_FX(src->m[2][3]);
    dst->_30 = FLOAT_TO_FX(src->m[3][0]);
    dst->_31 = FLOAT_TO_FX(src->m[3][1]);
    dst->_32 = FLOAT_TO_FX(src->m[3][2]);
    dst->_33 = FLOAT_TO_FX(src->m[3][3]);
}
