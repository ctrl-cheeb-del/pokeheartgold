#ifndef POKEHEARTGOLD_SCANLINE_EFFECT_INTERNAL_H
#define POKEHEARTGOLD_SCANLINE_EFFECT_INTERNAL_H
#include "global.h"

#include "heap.h"
#include "sys_task.h"
#include "sys_task_api.h"

typedef struct DoubleBuffer {
    void *buffers[2];
    u8 current, enabled, pad[2];
} DoubleBuffer;
typedef struct Scanline {
    u32 buffers[2][192];
    DoubleBuffer *doubleBuffer;
    SysTask *task;
    u32 unk608;
    s16 wave[192];
    u8 first, last;
    u16 pad78e;
    void *destination;
    u32 fill;
    s16 phase, speed;
} Scanline;
void MI_StopDma(u32);
void MI_WaitDma(u32);
void MI_HBlankDmaCopy32(u32, const void *, void *, u32);
void MI_HBlankDmaCopy16(u32, const void *, void *, u32);
DoubleBuffer *sub_02014A08(enum HeapID heap, void *first, void *second);
void sub_02014A38(DoubleBuffer *p);
void *sub_02014A4C(DoubleBuffer *p);
void *sub_02014A60(DoubleBuffer *p);
void sub_02014A78(DoubleBuffer *p, u8 enabled);
void sub_02014A8C(DoubleBuffer *p);
void sub_02014AA0(void);
void sub_02014AB0(void *src, void *dst, u32 size, int wide);
Scanline *sub_02014AD8(enum HeapID heap);
void sub_02014B08(Scanline *p, u8 first, u8 last, u32 step, fx32 amplitude, s16 speed, void *destination, u32 fill, u32 priority);
void sub_02014B9C(Scanline *p);
void sub_02014BD8(Scanline *p);
void *sub_02014BF8(Scanline *p);
void sub_02014C08(Scanline *p);
void sub_02014C40(Scanline *p);
void sub_02014C60(s16 *out, u32 count, u32 step, fx32 amplitude);
void sub_02014CBC(SysTask *task, void *data);
void sub_02014D68(void);
void sub_02014D70(Scanline *p);

DoubleBuffer *sub_02014A08(enum HeapID heap, void *first, void *second);
void sub_02014A38(DoubleBuffer *p);
void *sub_02014A4C(DoubleBuffer *p);
void *sub_02014A60(DoubleBuffer *p);
void sub_02014A78(DoubleBuffer *p, u8 enabled);
void sub_02014A8C(DoubleBuffer *p);
void sub_02014AA0(void);
void sub_02014AB0(void *src, void *dst, u32 size, int wide);
Scanline *sub_02014AD8(enum HeapID heap);
void sub_02014B08(Scanline *p, u8 first, u8 last, u32 step, fx32 amplitude, s16 speed, void *destination, u32 fill, u32 priority);
void sub_02014B9C(Scanline *p);
void sub_02014BD8(Scanline *p);
void *sub_02014BF8(Scanline *p);
void sub_02014C08(Scanline *p);
void sub_02014C40(Scanline *p);
void sub_02014C60(s16 *out, u32 count, u32 step, fx32 amplitude);
void sub_02014CBC(SysTask *task, void *data);
void sub_02014D68(void);
void sub_02014D70(Scanline *p);

#endif
