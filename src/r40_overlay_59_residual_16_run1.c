#include "r40_overlay_59_residual_16_private.h"

typedef struct R40Vec {
    s32 x;
    s32 y;
    s32 z;
} R40Vec;

typedef struct R40Node {
    u8 pad00[4];
    R40Vec pos;
} R40Node;

typedef struct R40Object {
    u8 pad00[0x20];
    R40Node **node;
    u8 pad24[4];
    R40Vec pos;
} R40Object;

void ov59_0223C474(void) {
    u32 tex = NNS_GfdDefaultFuncAllocTexVram(0x8000, FALSE, 0);
    u32 pltt = NNS_GfdDefaultFuncAllocPlttVram(0xa0, FALSE, 0);
    if (tex == 0) {
        GF_AssertFail();
    }
    if (pltt == 0) {
        GF_AssertFail();
    }
    sub_02014DA0();
}

u32 ov59_0223C4B4(u32 size, BOOL is4x4) {
    u32 key = NNS_GfdDefaultFuncAllocTexVram(size, is4x4, 0);
    sub_02015354(key);
    return (key << 16) >> 13;
}

u32 ov59_0223C4D0(u32 size, BOOL is4color) {
    u32 key = NNS_GfdDefaultFuncAllocPlttVram(size, is4color, 0);
    sub_02015394(key);
    return (key << 16) >> 13;
}

void ov59_0223C4EC(void *arg) {
    R40Object *work = arg;
    R40Vec offset = { 0, 0, 0 };

    offset.x = 0x3310;
    offset.y = -0x1020;
    offset.z = -0x1ae0;
    work->pos.x = offset.x + (*work->node)->pos.x;
    work->pos.y = offset.y + (*work->node)->pos.y;
    work->pos.z = offset.z + (*work->node)->pos.z;
}

void *ov59_0223C53C(u32 heapId) {
    void *buffer = Heap_Alloc((enum HeapID)heapId, 0x4800);
    void *emitter = sub_02014DB4(ov59_0223C4B4, ov59_0223C4D0, buffer, 0x4800, TRUE, (enum HeapID)heapId);
    void *camera = sub_02015524(emitter);

    if (camera != NULL) {
        Camera_SetPerspectiveClippingPlane(0x1000, 0x384000, camera);
    }
    return emitter;
}

void ov59_0223C584(void *work) {
    void *resource;

    *(void **)((u8 *)work + 0x24) = ov59_0223C53C(*(u32 *)work);
    sub_02015528(*(void **)((u8 *)work + 0x24), 1);
    resource = sub_02015264(0xf4, 0xa, *(u32 *)work);
    sub_0201526C(*(void **)((u8 *)work + 0x24), resource, 0xa, TRUE);
}
