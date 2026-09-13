#ifndef UNK_02060AF4_PRIVATE_H
#define UNK_02060AF4_PRIVATE_H

#include "global.h"

#include "map_object.h"

BOOL sub_02060D94(LocalMapObject *object, int x, int y, int z);
BOOL sub_02060DEC(LocalMapObject *object, int x, int z, int direction);
BOOL sub_02060BFC(LocalMapObject *object, int x, int y, int z);
BOOL sub_02060CA8(LocalMapObject *object, int x, int y, int z);
BOOL sub_020549A8(FieldSystem *fieldSystem, VecFx32 *position, int x, int z, s8 *outSlope);
u8 sub_0203993C(void);
BOOL sub_0203401C(int value);
u32 sub_02060AF4(LocalMapObject *object, VecFx32 *position, int x, int y, int z, int direction);

#endif
