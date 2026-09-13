#ifndef OVERLAY_43_RESIDUAL_28_PRIVATE_H
#define OVERLAY_43_RESIDUAL_28_PRIVATE_H

#include "global.h"

#define PTRAT(p, n) (*(void **)((u8 *)(p) + (n)))
#define ADD(p, n)   ((void *)((u8 *)(p) + (n)))

typedef struct Ov43WindowState {
    u16 value0;
    u16 value2;
    u16 value4;
    u16 padding6;
    void *owner;
    u32 first[8];
    u32 second[8];
} Ov43WindowState;

void ov43_0222DDA0(void *p, void *context);
void ov43_0222DDD0(void *p);
void ov43_0222DDF0(Ov43WindowState *state, u32 unused, const u16 *values, void *owner);

extern u8 ov43_0222EF20[];
extern void AddWindow(void *, void *, void *);
extern void FillWindowPixelBuffer(void *, u32);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);

#endif
