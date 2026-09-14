#ifndef POKEHEARTGOLD_OVERLAY99_RESIDUAL_12_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY99_RESIDUAL_12_PRIVATE_H

#include "global.h"

typedef struct Ov99ContextR12 {
    void *work;
    u8 pad04[8];
    u32 heapId;
} Ov99ContextR12;

typedef struct Ov99WorkR12 {
    void *source;
    u8 records[0x1B8];
    void *string;
} Ov99WorkR12;

typedef struct Ov99GridR12 {
    u8 pad00[0x18];
    void *sprites[38];
    u32 override;
    u8 padB4[8];
    void *entries[10];
} Ov99GridR12;

extern void *Heap_Alloc(u32, u32);
extern void MI_CpuFill8(void *, u8, u32);
extern void *String_New(u32, u32);
extern void ov99_021E92EC(Ov99ContextR12 *, void *, void *);
extern void ManagedSprite_SetDrawFlag(void *, int);
extern int ov99_021E8518(u8 *, int, void *);
extern void ov99_021E86D4(void *, int, int, int, int, int);

void ov99_021E9038(Ov99GridR12 *);
void ov99_021E93DC(Ov99ContextR12 *, void **);

#endif
