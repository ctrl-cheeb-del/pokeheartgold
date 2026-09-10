#ifndef POKEHEARTGOLD_UNK_02020B8C_H
#define POKEHEARTGOLD_UNK_02020B8C_H

#include "global.h"

fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
void VEC_MultAdd(fx32 scalar, const VecFx32 *a, const VecFx32 *b, VecFx32 *dest);
u16 FX_Atan2Idx(fx32 y, fx32 x);

int sub_02020B8C(int a, int b);
int sub_02020B94(int a, int b);
fx32 GetDistanceFromPointToLine(VecFx32 *a, VecFx32 *near, VecFx32 *far);
u16 CalcAngleBetweenVecs(VecFx32 *a, VecFx32 *b);
void sub_02020D2C(MtxFx33 *rotation, VecFx32 *a1);
void sub_02020DA4(MtxFx33 *rotation, u16 x, u16 y, u16 z);
BOOL sub_02020E80(const VecFx32 *a, const VecFx32 *b, const VecFx32 *c);
BOOL sub_02020EB0(const VecFx32 *a, const VecFx32 *b, const VecFx32 *c, const VecFx32 *d);

#endif // POKEHEARTGOLD_UNK_02020B8C_H
