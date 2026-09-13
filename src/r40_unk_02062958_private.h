#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct LocalMapObject LocalMapObject;
typedef struct MoveData {
    s32 distance;
    s32 accumulator;
    u16 limit;
    u16 progress;
    s8 direction;
    s8 speed;
    u8 parameter;
    s8 extra;
} MoveData;
MoveData *sub_0205F3C0(LocalMapObject *, int);
void sub_02060F78(LocalMapObject *);
void sub_02060F24(LocalMapObject *, int);
void MapObject_SetFlagsBits(LocalMapObject *, u32);
void MapObject_SetOrQueueFacing(LocalMapObject *, int);
void sub_0205F328(LocalMapObject *, int);
void MapObject_IncrementMovementStep(LocalMapObject *);
BOOL MapObject_CheckVisible(LocalMapObject *);
void PlaySE(int);
MoveData *sub_0205F3E4(LocalMapObject *);
void sub_0206101C(LocalMapObject *, int, int);
void sub_02061070(LocalMapObject *);
extern const s32 *_0210FACC[];
void MapObject_SetFacingVector(LocalMapObject *, const VecFx32 *);
void sub_0205F484(LocalMapObject *);
void sub_02062958(LocalMapObject *, s8, int, s8, u16, s16, u16);
BOOL MapObjectMovementCmd092_Step1(LocalMapObject *);
#endif
