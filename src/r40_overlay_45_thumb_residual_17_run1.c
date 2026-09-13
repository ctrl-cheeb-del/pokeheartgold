#include "r40_overlay_45_thumb_residual_17_private.h"

void ov45_0222BCC8(void **slot, u32 heapId) {
    *slot = PlayerProfile_New(heapId);
}

void ov45_0222BCD8(void **slot) {
    Heap_Free(*slot);
}

void ov45_0222BCE4(void **slot, void *src, u32 heapId) {
    void *work = Heap_Alloc(heapId, 0x94);
    MIi_CpuCopyFast((const u32 *)((u8 *)src + 0x20), (u32 *)work, 0x94);
    MI_CpuCopy8((u8 *)src + 0x10, (u8 *)work + 8, 0x10);
    ov45_0222A844(work, *slot, heapId);
    Heap_Free(work);
}
