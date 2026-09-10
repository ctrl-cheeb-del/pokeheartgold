#include "scanline_effect_internal.h"

DoubleBuffer *sub_02014A08(enum HeapID heap, void *first, void *second) {
    DoubleBuffer *p = Heap_Alloc(heap, sizeof(DoubleBuffer));
    memset(p, 0, sizeof(DoubleBuffer));
    p->enabled = 1;
    p->buffers[0] = first;
    p->buffers[1] = second;
    return p;
}

void sub_02014A38(DoubleBuffer *p) {
    GF_ASSERT(p);
    Heap_Free(p);
}

void *sub_02014A4C(DoubleBuffer *p) {
    GF_ASSERT(p);
    return p->buffers[p->current];
}

void *sub_02014A60(DoubleBuffer *p) {
    GF_ASSERT(p);
    return p->buffers[1 ^ p->current];
}

void sub_02014A78(DoubleBuffer *p, u8 enabled) {
    GF_ASSERT(p);
    p->enabled = enabled;
}

void sub_02014A8C(DoubleBuffer *p) {
    if (p && p->enabled) {
        p->current ^= 1;
    }
}

void sub_02014AA0(void) {
    MI_StopDma(0);
    MI_WaitDma(0);
}

void sub_02014AB0(void *src, void *dst, u32 size, int wide) {
    if (wide == 1) {
        MI_HBlankDmaCopy32(0, src, dst, size);
    } else {
        MI_HBlankDmaCopy16(0, src, dst, size);
    }
}

Scanline *sub_02014AD8(enum HeapID heap) {
    Scanline *p = Heap_Alloc(heap, sizeof(Scanline));
    memset(p, 0, sizeof(Scanline));
    p->doubleBuffer = sub_02014A08(heap, p->buffers[0], p->buffers[1]);
    return p;
}

void sub_02014B08(Scanline *p, u8 first, u8 last, u32 step, fx32 amplitude, s16 speed, void *destination, u32 fill, u32 priority) {
    GF_ASSERT(p);
    GF_ASSERT(p->task == NULL);
    p->first = first;
    p->last = last;
    p->phase = 0;
    p->speed = speed;
    p->destination = destination;
    p->fill = fill;
    sub_02014C60(p->wave, 192, step, amplitude);
    p->task = SysTask_CreateOnMainQueue(sub_02014CBC, p, priority);
    MIi_CpuClear32(p->fill, p->buffers[0], 0x300);
    MIi_CpuClear32(p->fill, p->buffers[1], 0x300);
}

void sub_02014B9C(Scanline *p) {
    GF_ASSERT(p);
    if (p->task) {
        SysTask_Destroy(p->task);
        p->task = NULL;
        memset(sub_02014A4C(p->doubleBuffer), p->fill, 0x300);
    }
}

void sub_02014BD8(Scanline *p) {
    sub_02014B9C(p);
    sub_02014D68();
    sub_02014A38(p->doubleBuffer);
    Heap_Free(p);
}

void *sub_02014BF8(Scanline *p) {
    return sub_02014A4C(p->doubleBuffer);
}

void sub_02014C08(Scanline *p) {
    if (p && p->task) {
        void *buffer;
        sub_02014A8C(p->doubleBuffer);
        buffer = sub_02014A4C(p->doubleBuffer);
        MIi_CpuClear32(p->fill, buffer, 0x300);
    }
}

void sub_02014C40(Scanline *p) {
    if (p && p->task) {
        sub_02014D68();
        sub_02014D70(p);
    }
}

void sub_02014C60(s16 *out, u32 count, u32 step, fx32 amplitude) {
    u16 angle = 0;
    u32 i;
    for (i = 0; i < count; i++) {
        *out = FX_Mul(FX_SinIdx(angle), amplitude) >> 12;
        angle += step;
        out++;
    }
}

void sub_02014CBC(SysTask *task, void *data) {
    Scanline *p = data;
    u32 *buffer = sub_02014A4C(p->doubleBuffer);
    u8 pos = p->phase / 100;
    int i;
    for (i = p->first; i <= p->last; i++) {
        s16 x = (s16)buffer[i];
        u16 y = (u16)(buffer[i] >> 16);
        x += p->wave[pos];
        buffer[i] = (y << 16) | (u16)x;
        pos = (pos + 1) % 192;
    }
    p->phase += p->speed;
    if (p->phase >= 19200) {
        p->phase %= 19200;
    } else if (p->phase < 0) {
        p->phase += 19200;
    }
}

void sub_02014D68(void) {
    sub_02014AA0();
}

void sub_02014D70(Scanline *p) {
    void *buffer;
    GF_ASSERT(p);
    buffer = sub_02014A60(p->doubleBuffer);
    DC_FlushRange(buffer, 0x300);
    sub_02014AB0(buffer, p->destination, 4, 1);
}
