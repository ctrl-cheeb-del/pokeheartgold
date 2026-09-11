#ifndef OVERLAY_01_021F944C_PRIVATE_H
#define OVERLAY_01_021F944C_PRIVATE_H

#include "global.h"

typedef struct FieldObjAnimData {
    u32 data[10];
} FieldObjAnimData;

typedef struct FieldObjAnimEntry {
    u32 id;
    FieldObjAnimData *data;
} FieldObjAnimEntry;

typedef struct FieldObjSys {
    u8 unk00[4];
    u32 count;
    u8 unk08[0xEC];
    FieldObjAnimEntry *entries;
    void *unkF8;
    void *unkFC;
} FieldObjSys;

extern void ov01_021FA370(FieldObjSys *, u32, FieldObjAnimData *);
extern FieldObjSys *sub_0205F1A0(void *);
extern int MapObjectManager_GetObjectCount(void *);
extern void *MapObjectManager_GetObjects2(void *);
extern BOOL MapObject_CheckActive(void *);
extern u32 MapObject_GetSpriteID(void *);
extern void MapObjectArray_NextObject(void **);
extern void *ov01_021FC4C4(u32, u32, u32, u32);
extern void *GF3dGfxRawResMan_Create(u32, u32);
extern void ov01_021F9B00(FieldObjSys *);
extern void ov01_021F9C24(FieldObjSys *);
extern void ov01_021F9D48(FieldObjSys *);
extern void ov01_021FA208(FieldObjSys *, u32);
extern void ov01_021FA210(FieldObjSys *, u32);
extern void ov01_021FA218(FieldObjSys *, u32);
extern void ov01_021FA220(FieldObjSys *, u32);
extern void ov01_021FA228(FieldObjSys *, u32);
extern void ov01_021FA230(FieldObjSys *, u32);
extern void ov01_021FA1EC(FieldObjSys *, void *);

FieldObjAnimData *ov01_021F9704(FieldObjSys *sys, u32 id);
BOOL ov01_021F9744(void *obj, u32 id, FieldObjAnimData *dst);
void ov01_021F9778(FieldObjSys *sys, u32 id);
void ov01_021F9798(FieldObjSys *sys);
BOOL ov01_021F97BC(void *mgr, void *self, u32 spriteId);
void ov01_021F9808(FieldObjSys *sys, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

#endif
