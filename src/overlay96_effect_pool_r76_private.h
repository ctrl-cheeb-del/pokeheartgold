#ifndef OVERLAY96_EFFECT_POOL_R76_PRIVATE_H
#define OVERLAY96_EFFECT_POOL_R76_PRIVATE_H

#include "global.h"

typedef struct Ov96EffectPoolEntry {
    u32 active;
    void *handle;
} Ov96EffectPoolEntry;

typedef struct Ov96EffectPoolRow {
    Ov96EffectPoolEntry entries[5];
    u32 next;
} Ov96EffectPoolRow;

extern void GF_AssertFail(void);
extern void ov96_021EB52C(void *handle, u32 a1, u32 a2);
extern void ov96_021EB564(void *handle, u32 value);
extern void ov96_021EB588(void *handle, const VecFx32 *position);
extern VecFx32 *ov96_021EB594(void *handle);
extern u32 ov96_021EB57C(void *handle);

void ov96_021FC698(Ov96EffectPoolRow *rows, u32 row, const VecFx32 *position);
void ov96_021FC6EC(Ov96EffectPoolRow *rows, u32 row, u32 yOffset);
void ov96_021FC758(Ov96EffectPoolEntry *entry);

#endif
