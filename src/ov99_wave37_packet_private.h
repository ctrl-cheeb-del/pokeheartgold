#ifndef SOL_R26_PRIVATE_H
#define SOL_R26_PRIVATE_H
#include "global.h"
#include "sprite_system.h"
#include "overlay_98_helpers_internal.h"
typedef union R26Flags { u32 raw; struct { u32 current:5; u32 pad:9; u32 scroll:5; u32 rest:13; } bits; } R26Flags;
typedef struct R26Work {
    BgConfig *bg;
    u32 unk004;
    void *narc;
    u32 heap;
    u8 pad010[4];
    u16 species[494];
    void *alloc3F0;
    R26Flags flags;
    u32 unk3F8;
    void *grid;
    Ov98TextContext *text;
    void *unk404;
    ManagedSprite *all[50];
} R26Work;
typedef struct R26Packet { u32 word0; u32 word1; u32 word2; } R26Packet;
u32 ov99_021E71E4(R26Work *, u32);
u32 ov99_021E7208(R26Work *, u32);
u32 ov99_021E723C(void **);
void ov98_0221E7E8(void *, R26Packet *, u32, u32, u32);
s32 ov99_021E7158(R26Work *);
void ov99_021E7428(R26Work *, s32);
void ov99_021E73E0(R26Work *, s32, u32);
void ov98_0221E970(void *, ManagedSprite *, R26Packet *, u32, u32);
void ov99_021E7450(R26Work *);
void ov99_021E7508(R26Work *);
void ov99_021E76D8(R26Work *, u32);
#endif
