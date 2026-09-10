#include "field_overlay_effects_internal.h"

void ov01_021F06EC(void *v, void *qv) {
    u8 *q = qv, *p = v;
    int i;
    SpriteTransfer_DeleteCharTransferTask(*(void **)q);
    SpriteTransfer_DeletePlttTransferTask(*(void **)(q + 4));
    for (i = 0; i < 4; i++) {
        DestroySingle2DGfxResObj(*(void **)(p + 0x12C), *(void **)q);
        q += 4;
        p += 4;
    }
}

void *ov01_021F0718(void *a, void *b, void *c, void *d, void *e, void *f) {
    void *cfg[8];
    void *ret;
    cfg[0] = *(void **)a;
    cfg[1] = (u8 *)b + 0x10;
    cfg[2] = c;
    cfg[3] = d;
    cfg[4] = e;
    cfg[5] = f;
    cfg[6] = (void *)1;
    cfg[7] = (void *)4;
    ret = Sprite_Create(cfg);
    if (ret == NULL) {
        GF_AssertFail();
    }
    return ret;
}

void ov01_021F074C(Triple *out, s32 x, s32 y, s32 z) {
    Triple value = { x, y, z };
    *out = value;
}

void *ov01_021F0768(int heap) {
    void *p = Heap_Alloc(heap, 0x30);
    memset(p, 0, 0x30);
    return p;
}

void ov01_021F0780(void *p) {
    Heap_Free(p);
}

void ov01_021F0788(void *v, s32 a, s32 b, s32 c, s32 d, s32 duration, void *window, int width, int height, u8 fill) {
    u8 *p = v;
    if (p[0x2E]) {
        GF_ASSERT(FALSE);
    }
    ov01_021EFE34((Interp *)p, a, b, duration);
    ov01_021EFE34((Interp *)(p + 0x14), c, d, duration);
    *(void **)(p + 0x28) = window;
    p[0x2C] = width;
    p[0x2D] = height;
    p[0x2F] = fill;
    p[0x2E] = 1;
}
