#ifndef PRIVATE_OVERLAY_80_0222ACA0_H
#define PRIVATE_OVERLAY_80_0222ACA0_H

#include "global.h"

typedef void (*Overlay80Callback)(void *, void *);
typedef struct {
    u32 word0;
    Overlay80Callback init;
    Overlay80Callback exit;
    u16 values[11];
    u8 byte26;
    u8 byte27;
    u8 padding[4];
} Overlay80Record;

extern const Overlay80Record ov80_0223B724[];

void GF_AssertFail(void);
void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void SetBgPriority(u32 bg, u32 priority);
void GfGfx_EngineATogglePlanes(u32 plane, u32 enable);
void *ov80_02239D74(void *, void *);
void ov80_02239DB8(void *);
void *ov80_022384D8(void *);
void ov80_022385B0(void *);

u32 ov80_0222ACA0(u32 index, u32 field);
void ov80_0222AD9C(void *a, void *b, u32 index);
void ov80_0222ADB4(void *a, void *b, u32 index);
void ov80_0222ADCC(void *unused, void **dest);
void ov80_0222ADDC(void *unused, void **dest);
void ov80_0222ADE8(void **args, void **dest);
void ov80_0222AE1C(void *unused, void **dest);
void ov80_0222AE28(void);
void ov80_0222AE2C(void);
void ov80_0222AE30(void);
void ov80_0222AE68(void);
void ov80_0222AE6C(void);
void ov80_0222AE80(void);
void ov80_0222AE84(void);
void ov80_0222AE9C(void);
void ov80_0222AEA0(void **args, void **dest);
void ov80_0222AEB0(void *unused, void **dest);
void ov80_0222AEBC(void);
void ov80_0222AEF4(void);

#endif
