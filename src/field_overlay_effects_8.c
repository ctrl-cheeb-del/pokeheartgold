#include "field_overlay_effects_internal.h"

void ov01_021F05C4(void *v, void *renderer, int heap) {
    u8 *p = v;
    int i;
    *(void **)p = G2dRenderer_Init(renderer, p + 4, 4);
    for (i = 0; i < 4; i++) {
        *(void **)(p + 0x12C) = Create2DGfxResObjMan(heap, i, 4);
        p += 4;
    }
}

void ov01_021F05F4(void *v) {
    u8 *p = v;
    int i;
    SpriteList_Delete(*(void **)p);
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(*(void **)(p + 0x12C));
        p += 4;
    }
}
