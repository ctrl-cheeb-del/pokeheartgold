#ifndef POKEHEARTGOLD_MAP_OBJECT_JUMP_INTERNAL_H
#define POKEHEARTGOLD_MAP_OBJECT_JUMP_INTERNAL_H
#include "global.h"

#include "constants/sndseq.h"
typedef struct Vec3 {
    s32 x, y, z;
} Vec3;
typedef struct JumpData {
    u8 angle;
    s8 dx;
    s8 dy;
    s8 dz;
    fx32 stepX;
    fx32 stepY;
    fx32 stepZ;
    Vec3 origin;
} JumpData;
typedef struct MoveCmd {
    s8 facing;
    s8 frames;
    u8 step;
    u8 param;
    s32 savedY;
    JumpData *data;
} MoveCmd;
extern MoveCmd *sub_0205F3C0(void *, int);
extern MoveCmd *sub_0205F3E4();
extern void *Heap_AllocAtEnd();
extern void Heap_Free();
extern fx32 FX_Div();
extern void MapObject_CopyPositionVector();
extern void MapObject_SetFlagsBits();
extern void MapObject_SetOrQueueFacing();
extern void sub_0205F328();
extern void MapObject_IncrementMovementStep();
extern void sub_02060F78();
extern int MapObject_CheckVisible();
extern void PlaySE();
extern void *MapObject_GetFieldSystem();
extern int MapObject_CheckFlag29();
extern int sub_02061248();
extern void MapObject_SetPositionVector();
extern fx32 GF_SinDegNoWrap();
extern void sub_0205F9A0();
extern void MapObject_SetFacingVector();
extern void MapObject_AddCurrentX();
extern void MapObject_AddCurrentY();
extern void MapObject_AddCurrentZ();
extern void sub_02061070();
extern void sub_0205F484();
extern void GF_AssertFail(void);
void sub_020632B0(void *, int, int, int, s8, int, u16);
BOOL MapObjectMovementCmd108_Step1(void *);

#endif
