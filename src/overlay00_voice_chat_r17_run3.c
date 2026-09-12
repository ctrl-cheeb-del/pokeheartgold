#include "overlay00_voice_chat_r17_private.h"

BOOL ov00_021E77A4(u32 value, void *a1, void *a2) {
    if (_0221A684.state == NULL) {
        return FALSE;
    }
    if (VCT_HandleData((u8)value, a1, a2, _0221A684.state)) {
        return TRUE;
    }
    return FALSE;
}

void ov00_021E77CC(void **allocation, void **aligned, u32 size, u32 heapId) {
    u32 allocSize = size + 0x20;
    *allocation = Heap_Alloc(heapId, allocSize);
    MI_CpuFill8(*allocation, 0, allocSize);
    *aligned = (void *)(((u32)*allocation + 0x1F) & ~0x1F);
}
