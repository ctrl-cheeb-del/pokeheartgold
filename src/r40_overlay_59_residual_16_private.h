#ifndef OVERLAY_59_RESIDUAL_16_R40_PRIVATE_H
#define OVERLAY_59_RESIDUAL_16_R40_PRIVATE_H

#include <nnsys/gfd.h>

#include "global.h"

#include "heap.h"

void GF_AssertFail(void);
void sub_02014DA0(void);
void sub_02015354(u32 key);
void sub_02015394(u32 key);
void sub_02015528(void *emitter, int type);
void *sub_02015264(u32 narcId, u32 member, u32 heapId);
void sub_0201526C(void *emitter, void *resource, u32 count, BOOL loadNow);

void ov59_0223C474(void);
u32 ov59_0223C4B4(u32 size, BOOL is4x4);
u32 ov59_0223C4D0(u32 size, BOOL is4color);
void *ov59_0223C53C(u32 heapId);
void ov59_0223C584(void *work);
void ov59_0223C4EC(void *work);
void *Heap_Alloc(enum HeapID heapId, u32 size);
void *sub_02014DB4(u32 (*tex)(u32, BOOL), u32 (*pltt)(u32, BOOL), void *buffer, u32 size, BOOL makeCamera, enum HeapID heapId);
void *sub_02015524(void *emitter);
void Camera_SetPerspectiveClippingPlane(s32 near, s32 far, void *camera);

#endif
