#ifndef GEOMETRY_MATH_R40_20B8C_PRIVATE_H
#define GEOMETRY_MATH_R40_20B8C_PRIVATE_H

#include "global.h"

fx32 FX_Div(fx32 numerator, fx32 denominator);
void sub_02020E10(s32 angle, fx32 first, fx32 second, fx32 *outSecond, fx32 *outFirst);
BOOL sub_02020E80(const VecFx32 *first, const VecFx32 *second, const VecFx32 *third);

#endif
