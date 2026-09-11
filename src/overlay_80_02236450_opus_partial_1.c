#include "overlay_80_02236450_opus_partial_internal.h"

u32 ov80_02236450(void *work, void *record, int trainerId, u32 index, u32 a4, u32 a5, u32 a6, int heapId) {
    u8 *p = work;
    void *raw;
    u32 ret;

    raw = ov80_02229F04(record, trainerId, heapId, ov80_02236B04(p[0xf]));
    ret = ov80_022364A4(work, raw, trainerId, (u8 *)record + 0x30, index, a4, a5, a6, heapId);
    Heap_Free(raw);
    return ret;
}
