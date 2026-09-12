#include "overlay49_interpolation_pool_private.h"

void *ov49_022652E8(void *arg0, void *arg1, void *arg2, void *arg3, u32 heapId, u32 size) {
    void *narc;
    void *work = Heap_Alloc(heapId, 0x1082C);

    memset(work, 0, 0x1082C);
    PTR_AT(work, 0) = arg0;
    PTR_AT(work, 4) = arg3;
    PTR_AT(work, 8) = arg2;
    PTR_AT(work, 0xC) = arg1;
    narc = NARC_New(0xD1, heapId);
    HeapExp_FndInitAllocator((u8 *)work + 0x1081C, size, 4);
    ov49_02265698(work, narc, size);
    ov49_02265738(work, narc, size);
    ov49_022657B4(work, narc, size);
    NARC_Delete(narc);
    return work;
}

void ov49_0226535C(void *work) {
    ov49_0226571C(work);
    ov49_02265760(work);
    ov49_02265858(work);
    Heap_Free(work);
}

void ov49_02265378(void *work) {
    int i;
    u8 *entry = (u8 *)work;
    u32 stride = 0xD1;
    i = 0;
    entry += 0x10;
    stride <<= 4;
    for (; i < 20; i++, entry += stride) {
        ov49_022658E4(work, entry);
    }
}

void ov49_02265398(void *work) {
    int i;
    u8 *entry;
    u32 stride;

    ov49_02258DAC(PTR_AT(work, 4));
    entry = (u8 *)work;
    stride = 0xD1;
    i = 0;
    entry += 0x10;
    stride <<= 4;
    for (; i < 20; i++, entry += stride) {
        ov49_02265920(work, entry);
    }
}

void ov49_022653C0(void *work, u32 index, u32 value) {
    void *result;

    if (index >= 20) {
        GF_AssertFail();
    }
    result = ov49_02258D70(PTR_AT(work, 4), index);
    if (result != NULL) {
        ov49_02265890(work, (u8 *)work + 0x10 + index * 0xD10, result, value);
    }
}

BOOL ov49_022653F0(void *work, u32 index) {
    if (ov49_02265958((u8 *)work + 0x10 + index * 0xD10) != 1) {
        return TRUE;
    }
    return FALSE;
}

void ov49_0226540C(s32 *out, s32 x0, s32 x1, s32 y0, s32 y1, s32 z0, s32 z1, s32 duration) {
    out[0] = duration;
    out[1] = x0;
    out[4] = x1 - x0;
    out[5] = x0;
    out[2] = y0;
    out[6] = y1 - y0;
    out[7] = y0;
    out[3] = z0;
    out[8] = z1 - z0;
    out[9] = z0;
}

BOOL ov49_02265434(Ov49Interpolation *work, s32 current) {
    float durationX;
    float durationY;
    float durationZ;
    BOOL finished = FALSE;
    s32 delta;
    s32 scaled;

    if (current > work->duration) {
        current = work->duration;
        finished = TRUE;
    }

    delta = work->deltaX;
    if (delta != 0) {
        if (work->duration > 0) {
            durationX = (float)(work->duration << 12) + 0.5f;
        } else {
            durationX = (float)(work->duration << 12) - 0.5f;
        }
        scaled = (s32)((_ll_mul((s64)(s32)(current > 0 ? (float)(current << 12) + 0.5f : (float)(current << 12) - 0.5f), (s64)delta) + 0x800) >> 12);
        work->x = work->startX + FX_Div(scaled, (s32)durationX);
    }

    delta = work->deltaY;
    if (delta != 0) {
        if (work->duration > 0) {
            durationY = (float)(work->duration << 12) + 0.5f;
        } else {
            durationY = (float)(work->duration << 12) - 0.5f;
        }
        scaled = (s32)((_ll_mul((s64)(s32)(current > 0 ? (float)(current << 12) + 0.5f : (float)(current << 12) - 0.5f), (s64)delta) + 0x800) >> 12);
        work->y = work->startY + FX_Div(scaled, (s32)durationY);
    }

    delta = work->deltaZ;
    if (delta != 0) {
        if (work->duration > 0) {
            durationZ = (float)(work->duration << 12) + 0.5f;
        } else {
            durationZ = (float)(work->duration << 12) - 0.5f;
        }
        scaled = (s32)((_ll_mul((s64)(s32)(current > 0 ? (float)(current << 12) + 0.5f : (float)(current << 12) - 0.5f), (s64)delta) + 0x800) >> 12);
        work->z = work->startZ + FX_Div(scaled, (s32)durationZ);
    }
    return finished;
}
