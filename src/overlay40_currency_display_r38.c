#include "overlay40_currency_display_r38_private.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void *ov40_02242FAC(u32 heapId, u32 stringLength, const u32 *values, u32 finalValue) {
    u8 *work;
    int i;
    const u32 *src;
    u32 *dst;

    work = Heap_Alloc(heapId, 0x20);
    MI_CpuFill8(work, 0, 0x20);
    U32(work, 0) = stringLength;
    PTR(work, 0x18) = String_New(stringLength + 1, heapId);
    U32(work, 0x1C) = finalValue;
    i = 0;
    src = values;
    dst = (u32 *)work;
    while (i < 3) {
        dst[1] = *src;
        i++;
        src++;
        dst++;
    }
    *(u32 *)(work + i * 4 + 4) = values[i - 1];
    return work;
}

void ov40_02242FF8(u8 *work) {
    if (PTR(work, 0x18) == NULL) {
        GF_AssertFail();
    }
    if (work == NULL) {
        GF_AssertFail();
    }
    String_Delete(PTR(work, 0x18));
    Heap_Free(work);
}

void ov40_0224301C(u8 *work, u32 value) {
    u32 previous = U32(work, 0x208);
    U32(work, 0x20C) = previous;
    U32(work, 0x208) = value;
    U32(work, 0x210) = 0;
    U32(work, 0x214) = 0;
    U32(work, 0x218) = 0;
    U32(work, 0x21C) = 0;

    if (U32(work, 0x208) != 0) {
        U32(work, 0x210) = U16(work, 0x1E4 + (U32(work, 0x208) - 1) * 4);
        U32(work, 0x214) = U16(work, 0x1E6 + (U32(work, 0x208) - 1) * 4);
    }
    if (U32(work, 0x20C) != 0) {
        U32(work, 0x218) = U16(work, 0x1E4 + (U32(work, 0x20C) - 1) * 4);
        U32(work, 0x21C) = U16(work, 0x1E6 + (U32(work, 0x20C) - 1) * 4);
    }
}
