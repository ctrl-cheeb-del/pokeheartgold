#ifndef POKEHEARTGOLD_FIELD_POISON_EFFECT_INTERNAL_H
#define POKEHEARTGOLD_FIELD_POISON_EFFECT_INTERNAL_H

#include "global.h"

#include "constants/heap.h"
#include "constants/sndseq.h"

#include "field/hblank_system.h"

#include "assert.h"
#include "heap.h"
#include "overlay_01_021FB5D4.h"
#include "scanline_effect_internal.h"
#include "sys_task.h"
#include "sys_task_api.h"

// No tracked header declares these; overlay_01_021FB4C0.s still owns them.
typedef void (*HBlankTaskFunc)(void *, void *);
void *ov01_021FB530(HBlankSystem *hBlankSystem, HBlankTaskFunc func, void *data);
void ov01_021FB554(void *task);

// SDK symbol with no tracked prototype in lib/include.
void G3X_SetHOffset(int offset);

void PlaySE(u16 seq);

typedef struct PoisonEffect {
    u32 state;                  // 0x000
    s32 counter;                // 0x004
    u32 seqNo;                  // 0x008
    u16 buffers[2][192];        // 0x00c, 0x18c
    DoubleBuffer *doubleBuffer; // 0x30c
    HBlankSystem *hBlankSystem; // 0x310
    void *hblankTask;           // 0x314
    u32 hblankReady;            // 0x318
    SysTask *mainTask;          // 0x31c
    SysTask *vblankTask;        // 0x320
    SysTask *vblankTask2;       // 0x324
} PoisonEffect;                 // 0x328

#endif
