#include "overlay59_apricorn_results_internal.h"

void *ov59_0223C298(u32 heapId) {
    void *work = Heap_Alloc(heapId, 0x28);

    MI_CpuFill8(work, 0, 0x28);
    OV59_RESULT_U32(work, 0) = heapId;
    OV59_RESULT_PTR(work, 4) = GF_3DVramMan_Create(heapId, 0, 2, 0, 1, ov59_0223C3F0);
    ov59_0223C474(OV59_RESULT_PTR(work, 4));
    ov59_0223C5C4(work, heapId);
    ov59_0223C584(work);
    OV59_RESULT_PTR(work, 0xC) = PokepicManager_Create(heapId);
    GfGfx_EngineATogglePlanes(1, 1);
    *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & ~3) | 1;
    return work;
}
