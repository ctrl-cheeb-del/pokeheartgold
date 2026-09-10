#ifndef PRIVATE_OVERLAY_80_02239960_H
#define PRIVATE_OVERLAY_80_02239960_H

#include "global.h"

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void sub_02014DA0(void);
void *sub_02014DB4(u32 (*tex)(u32, int), u32 (*pltt)(u32, int), void *buffer, u32 size, u32 flag, u32 heapId);
void sub_02014EBC(void *object);
void *sub_020154D0(void *object);
void *sub_02015524(void *object);
void sub_02015528(void *object, void *camera);
u32 sub_02015420(void);
s32 sub_0201543C(void);
void sub_02015460(void);
s32 sub_020154B0(void *object);
void sub_02015354(u32 key);
void sub_02015394(u32 key);
void *sub_02015264(u32 narcId, u32 member, u32 heapId);
void sub_0201526C(void *object, void *resource, u32 count, u32 flag);
void Camera_SetPerspectiveClippingPlane(u32 near, u32 far, void *camera);
void Thunk_G3X_Reset(void);
void GF_AssertFail(void);

void *ov80_02239960(u32 heapId);
void ov80_02239980(void *manager);
void *ov80_022399A4(void *manager, u32 index, u32 member, void *camera);
void ov80_02239A1C(void *manager, u32 index);
BOOL ov80_02239A38(void);
void *ov80_02239A60(void *manager, u32 index);
BOOL ov80_02239A74(void *manager);
void ov80_02239A98(void *object);
u32 ov80_02239AB0(u32 size, int flag);
u32 ov80_02239AD4(u32 size, int flag);

#endif
