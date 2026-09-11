#ifndef TO30_UNK_020603F8_PRIVATE_H
#define TO30_UNK_020603F8_PRIVATE_H

#include "global.h"
#define MAPOBJECTFLAG_UNK15 (1 << 15)
#define MAPOBJECTFLAG_UNK20 (1 << 20)

typedef struct LocalMapObject LocalMapObject;
typedef struct MapObjectManager MapObjectManager;

MapObjectManager *MapObject_GetManager(LocalMapObject *object);
BOOL MapObjectManager_NotEndMovement(MapObjectManager *manager);
u32 MapObject_GetFlagsBitsMask(LocalMapObject *object, u32 mask);
void MapObject_SetFlagsBits(LocalMapObject *object, u32 mask);
void MapObject_ClearFlagsBits(LocalMapObject *object, u32 mask);
BOOL MapObject_CheckVisible(LocalMapObject *object);

u32 sub_0205F524(LocalMapObject *object);
BOOL sub_02060E54(LocalMapObject *object, int behavior);
BOOL sub_02060EBC(LocalMapObject *object, int behavior);

BOOL MetatileBehavior_IsTallGrass(int behavior);
BOOL MetatileBehavior_IsVeryTallGrass(int behavior);
BOOL MetatileBehavior_IsPuddle(int behavior);
BOOL MetatileBehavior_IsShallowWater(int behavior);
BOOL MetatileBehavior_IsMud(int behavior);
BOOL MetatileBehavior_IsReflective(int behavior);
BOOL MetatileBehavior_IsIce(int behavior);

void ov01_021FD640(LocalMapObject *object);
void ov01_021FD684(LocalMapObject *object);
void ov01_021FF74C(LocalMapObject *object);

void sub_020603F8(LocalMapObject *object, int previous, u8 current, int effect);
void sub_02060530(LocalMapObject *object, int behavior, int unused, int effect);
void sub_0206064C(LocalMapObject *object, int behavior);

#endif
