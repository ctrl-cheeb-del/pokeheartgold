#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

void ov99_021E6938(R99 *w) {
    volatile u8 *base = (volatile u8 *)0x027e0000;
    SpriteSystem_TransferOam(w);
    DoScheduledBgGpuUpdates(P(w, 4));
    *(volatile u32 *)(base + 0x3ff8) |= 1;
}
