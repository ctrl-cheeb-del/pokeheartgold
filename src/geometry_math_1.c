#include "math_util.h"
#include "unk_02020B8C.h"

int sub_02020B8C(int a, int b) {
    return a < b ? a : b;
}

int sub_02020B94(int a, int b) {
    return a > b ? a : b;
}

fx32 GetDistanceFromPointToLine(VecFx32 *point, VecFx32 *near, VecFx32 *far) {
    VecFx32 line, delta, distance, projected, zero = { 0, 0, 0 };
    fx32 scale;
    VEC_Subtract(far, near, &line);
    VEC_Subtract(point, near, &delta);
    scale = FX_Div(VEC_DotProduct(&line, &delta),
        FX_Mul(line.x, line.x) + FX_Mul(line.y, line.y) + FX_Mul(line.z, line.z));
    VEC_MultAdd(scale, &line, &zero, &projected);
    VEC_Subtract(&projected, &delta, &distance);
    return VEC_Mag(&distance);
}

u16 CalcAngleBetweenVecs(VecFx32 *a, VecFx32 *b) {
    VecFx32 na, nb;
    fx32 dot;
    fx32 cross;
    VEC_Normalize(a, &na);
    VEC_Normalize(b, &nb);
    dot = FX_Mul(na.z, nb.z) + FX_Mul(na.x, nb.x);
    cross = FX_Mul(na.z, nb.x) - FX_Mul(na.x, nb.z);
    if (dot == 0) {
        if (cross > 0) {
            return 0x4000;
        }
        return 3 << 14;
    }
    return FX_Atan2Idx(cross, dot);
}

void sub_02020D2C(MtxFx33 *rotation, VecFx32 *angles) {
    MtxFx33 temp;
    MTX_RotX33_(rotation, FX_SinIdx((u16)angles->x), FX_CosIdx((u16)angles->x));
    MTX_RotY33_(&temp, FX_SinIdx((u16)angles->y), FX_CosIdx((u16)angles->y));
    MTX_Concat33(rotation, &temp, rotation);
    MTX_RotZ33_(&temp, FX_SinIdx((u16)angles->z), FX_CosIdx((u16)angles->z));
    MTX_Concat33(rotation, &temp, rotation);
}

void sub_02020DA4(MtxFx33 *rotation, u16 x, u16 y, u16 z) {
    MtxFx33 temp;
    fx32 sin, cos;
    cos = GF_CosDegNoWrap(x);
    sin = GF_SinDegNoWrap(x);
    MTX_RotX33_(rotation, sin, cos);
    cos = GF_CosDegNoWrap(y);
    sin = GF_SinDegNoWrap(y);
    MTX_RotY33_(&temp, sin, cos);
    MTX_Concat33(rotation, &temp, rotation);
    cos = GF_CosDegNoWrap(z);
    sin = GF_SinDegNoWrap(z);
    MTX_RotZ33_(&temp, sin, cos);
    MTX_Concat33(rotation, &temp, rotation);
}
