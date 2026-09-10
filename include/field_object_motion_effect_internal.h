#ifndef PRIVATE_OV01_021FFC0C_H
#define PRIVATE_OV01_021FFC0C_H
#include "global.h"
typedef struct LocalCtx {
    void *owner;
} LocalCtx;
typedef struct LocalState {
    u32 stage, sprite, id, mapId, pad10, onFloor;
    s32 x, pad1c, z;
    void *fieldSystem, *resource;
    u32 pad2c;
    void *mapObject;
    u32 pad34;
    s8 facing;
    u8 pad39[3];
    void *effect;
} LocalState;
void *ov01_021F1430(void *, u32, u32, u32);
void ov01_021F1448(void *);
void ov01_021F18D4(void *, int, int);
void ov01_021F1908(void *, int, int);
void ov01_021F1930(void *, int, int, int);
void ov01_021F1758(void *, int, int, int, int, int, const void *);
void ov01_021F18FC(void *, int);
void ov01_021F1924(void *, int);
void ov01_021F1970(void *, int);
void ov01_021F18C8(void *, int);
void *sub_02068D98(void *);
int sub_02068D90(void *);
void sub_02068DA8(void *, const VecFx32 *);
void sub_02068DB8(void *, VecFx32 *);
int MapObject_GetSpriteID(void *);
int MapObject_GetID(void *);
int MapObject_GetMapID(void *);
fx32 MapObject_GetPositionVectorYCoord(void *);
BOOL MapObject_TestFlagsBits(void *, u32);
BOOL sub_0205F0A8(void *, int, int);
BOOL sub_0205F0F8(void *, int, int, int);
int sub_0206121C(void *, VecFx32 *);
void *ov01_021F1740(void *, int, const VecFx32 *);
void sub_02023DA4(void *);
void sub_02023EA4(void *, BOOL);
void sub_02023F1C(void *, fx32);
void sub_02023F04(void *, fx32);
fx32 sub_02023F70(void *);
void sub_02023E50(void *, const VecFx32 *);
void ov01_021F1640(void *);
int MapObject_GetXCoord(void *);
int MapObject_GetZCoord(void *);
int MapObject_GetFacingDirection(void *);
LocalCtx *ov01_021FFC0C(void *);
void ov01_021FFC28(LocalCtx *);
void ov01_021FFC38(LocalCtx *);
void ov01_021FFC80(LocalCtx *);
BOOL ov01_021FFCA8(void *, LocalState *);
void ov01_021FFD64(void *, LocalState *);
void ov01_021FFD70(void *, LocalState *);
void ov01_021FFE98(void *, LocalState *);
#endif
