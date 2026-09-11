#include "overlay32_partial_internal.h"

void ov32_0225DAC0(u8 *work) {
    ov32_0225DCD4(work);
    ov32_0225DB00(work);
    SpriteList_Delete(*(void **)(work + 0x14C));
}

void ov32_0225DADC(u8 *work) {
    u32 offset = 0x278;
    u32 i = 0;
    u32 one = 1;
    do {
        *(void **)(work + offset) = Create2DGfxResObjMan(one, i, 8);
        i++;
        work += 4;
    } while (i < 4);
}

void ov32_0225DB00(u8 *work) {
    u32 offset = 0x278;
    u32 i = 0;
    do {
        Destroy2DGfxResObjMan(*(void **)(work + offset));
        i++;
        work += 4;
    } while (i < 4);
}
