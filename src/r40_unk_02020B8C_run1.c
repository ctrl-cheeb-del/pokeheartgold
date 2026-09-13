#include "r40_unk_02020B8C_private.h"

void sub_02020E10(s32 angle, fx32 first, fx32 second, fx32 *outSecond, fx32 *outFirst) {
    fx32 ratio = FX_Div(FX_SinIdx(angle), FX_CosIdx(angle));
    fx32 value = FX_Mul(first, ratio);

    value = FX_Mul(value, 2 * FX32_ONE);
    *outFirst = value;
    *outSecond = FX_Mul(*outFirst, second);
}

BOOL sub_02020E80(const VecFx32 *first, const VecFx32 *second, const VecFx32 *third) {
    s32 thirdTerm = second->x * (third->y - first->y);
    s32 secondTerm = first->x * (second->y - third->y);
    s32 firstTerm = third->x * (first->y - second->y);

    return firstTerm + secondTerm + thirdTerm >= 0;
}
