#include "ov49_wave34_windows_r40_3_private.h"

void ov49_0225C844(Ov49WindowWorkR40 *work, void *bgConfigHolder, void *narc, u32 heapId) {
    s32 i;

    AddWindow(*(void **)bgConfigHolder, work->window, ov49_0226970C);
    for (i = 0; i < 3; i++) {
        work->screenData[i] = GfGfxLoader_GetScrnDataFromOpenNarc(narc, i + 0x38, 0, &work->destinations[i], heapId);
    }
    work->touchController = TouchHitboxController_Create(ov49_022696F4, 1, ov49_0225CB50, work, heapId);
    work->flag = 1;
}
