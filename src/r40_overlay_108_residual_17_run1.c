#include "r40_overlay_108_residual_17_private.h"

void ov108_021E867C(R40Ov108Sub17 *s) {
    R40Ov108Counts counts = ov108_021EA978;
    u32 i;
    s->spriteList = G2dRenderer_Init(s->spriteCount, &s->renderer, s->heapId);
    for (i = 0; i < 4; i++) {
        u32 j;
        s->managers[i] = Create2DGfxResObjMan(counts.value[i], i, s->heapId);
        s->lists[i] = Create2DGfxResObjList(counts.value[i], s->heapId);
        for (j = 0; j < s->lists[i]->count; j++) {
            s->lists[i]->objects[j] = NULL;
        }
    }
    ov108_021E8758(s);
}
