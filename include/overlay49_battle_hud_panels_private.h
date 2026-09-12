#ifndef OV49_HUD_PANELS_PRIVATE_H
#define OV49_HUD_PANELS_PRIVATE_H

#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))

typedef struct Ov49Blk {
    u32 w[8];
} Ov49Blk;

typedef struct Ov49Hud {
    void *unk00;
    void *unk04;
    void *unk08;
    void *unk0C;
    u8 unk10[0x100];
} Ov49Hud;

typedef struct Ov49Owner {
    u32 unk00;
    u32 unk04;
    Ov49Blk unk08;
} Ov49Owner;

#endif
