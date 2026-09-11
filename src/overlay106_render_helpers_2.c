#include "overlay106_render_helpers_private.h"




typedef struct { u32 v[9]; } Ov106Matrix;
typedef struct { u32 v[3]; } Ov106Vec;

void ov106_021E5BBC(u8 *data) {
    u16 i;
    for (i = 0; i < *(u32 *)(data + 0x3FC); i++) {
        u8 *model = data + 0x1C + i * 0x7C;
        u16 j;
        for (j = 0; j < 4; j++) {
            u8 *slot = model + j * 4;
            if (*(void **)(slot + 0x5C) != NULL) {
                NNS_G3dFreeAnmObj((NNSFndAllocator *)(data + 8), *(NNSG3dAnmObj **)(slot + 0x6C));
                Heap_Free(*(void **)(slot + 0x5C));
            }
        }
        Heap_Free(*(void **)(model + 0x58));
    }
}

void ov106_021E5C30(u8 *data) {
    Ov106Matrix matrix = *(const Ov106Matrix *)ov106_021E6D8C;
    Ov106Vec other = *(const Ov106Vec *)_021E6D70;
    Ov106Vec zero = { 0, 0, 0 };
    u32 i;
    Thunk_G3X_Reset();
    Camera_PushLookAtToNNSGlb();
    for (i = 0; i < *(u32 *)(data + 0x3FC); i++) {
        u8 *model = data + 0x1C + i * 0x7C;
        u32 j = 0;
        u8 *slot = model;
        while (j < 4) {
            u8 *obj = *(u8 **)(slot + 0x6C);
            if (obj != NULL) {
                s32 frame = *(s32 *)obj;
                s32 end = *(u16 *)(*(u8 **)(obj + 8) + 4) << 12;
                if (frame + 0x1000 < end) *(s32 *)obj = frame + 0x1000;
            }
            j++;
            slot += 4;
        }
        GF3dRender_DrawModel(model, &zero, &matrix, &other);
    }
    RequestSwap3DBuffers(0, 0);
}

BOOL ov106_021E5CD0(u8 *data, u32 index) {
    u32 offset = 0x7C * index;
    int step;
    u32 i;
    data += 0x1C;
    step = 0x1000;
    i = 0;
    data += offset;
    while (i < 4) {
        u8 *obj = *(u8 **)(data + 0x6C);
        if (obj != NULL) {
            s32 frame = *(s32 *)obj + step;
            s32 end = *(u16 *)(*(u8 **)(obj + 8) + 4) << 12;
            if (frame < end) return TRUE;
        }
        i++;
        data += 4;
    }
    return FALSE;
}
