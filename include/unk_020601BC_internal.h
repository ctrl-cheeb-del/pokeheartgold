#ifndef UNK_020601BC_PRIVATE_H
#define UNK_020601BC_PRIVATE_H

#include "global.h"

#include "map_object.h"

BOOL MetatileBehavior_IsTallGrass(u8 behavior);
BOOL MetatileBehavior_IsVeryTallGrass(u8 behavior);
void ov01_021FF070(LocalMapObject *object, int mode);
BOOL ov01_022055DC(LocalMapObject *object);
void ov01_02205604(LocalMapObject *object, int *x, int *z);
int GetMetatileBehavior(FieldSystem *fieldSystem, int x, int z);
void ov01_021FF0E4(LocalMapObject *object, int mode, int x, int z, int one);
void ov01_021FF964(LocalMapObject *object, int mode, int x, int z, int one);
BOOL sub_0205BA94(u32 value);
BOOL sub_02060EA4(LocalMapObject *object, u32 value);
BOOL sub_02060ED4(LocalMapObject *object, u32 value);
void ov01_021FE3E8(LocalMapObject *object);
void ov01_021FE3F4(LocalMapObject *object);
void ov01_021FE3C4(LocalMapObject *object);
void ov01_021FE3D0(LocalMapObject *object);
void ov01_021FE3DC(LocalMapObject *object);

void sub_020601BC(LocalMapObject *object, u8 behavior);
void sub_02060274(LocalMapObject *object, u8 behavior);
void sub_02060328(LocalMapObject *object, int unused, u32 value, const u16 *data);

#endif
