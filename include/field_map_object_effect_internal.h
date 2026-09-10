#ifndef PRIVATE_OV01_021FF464_H
#define PRIVATE_OV01_021FF464_H
#include "global.h"
typedef struct LocalCtx {
    void *owner;
} LocalCtx;
typedef struct LocalState {
    u32 stage, sprite, id, mapId, pad10, data14;
    void *resource;
    u32 pad1c;
    void *mapObject, *effect;
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
void *ov01_021F146C(void *);
void *ov01_021F1450(void *, int);
void *MapObject_GetFieldSystem(void *);
int MapObject_GetPriorityPlusValue(void *, int);
void ov01_021F1620(void *, const void *, const VecFx32 *, void *, void *, int);
void *sub_02068D98(void *);
int sub_02068D90(void *);
void sub_02068DA8(void *, const VecFx32 *);
int MapObject_GetSpriteID(void *);
int MapObject_GetID(void *);
int MapObject_GetMapID(void *);
void *ov01_021F1740(void *, int, const VecFx32 *);
BOOL MapObject_TestFlagsBits(void *, u32);
void sub_02023EA4(void *, BOOL);
void sub_02023DA4(void *);
BOOL sub_0205F0F8(void *, int, int, int);
BOOL MapObject_CheckFlag26(void *);
void ov01_021F1640(void *);
void sub_02023F04(void *, fx32);
fx32 sub_02023F70(void *);
void sub_02023F1C(void *, fx32);
void MapObject_CopyPositionVector(void *, VecFx32 *);
void MapObject_CopyFacingVector(void *, VecFx32 *);
void sub_02023E50(void *, const VecFx32 *);
LocalCtx *ov01_021FF464(void *);
void ov01_021FF480(LocalCtx *);
void ov01_021FF490(LocalCtx *);
void ov01_021FF4D4(LocalCtx *);
void ov01_021FF4FC(void *, void *);
BOOL ov01_021FF54C(void *, LocalState *);
void ov01_021FF5B8(void *, LocalState *);
void ov01_021FF5C4(void *, LocalState *);
void ov01_021FF658(void *, LocalState *);
#endif
