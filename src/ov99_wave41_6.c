#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

void ov99_021E6218(R99 *w) {
    void *obj = P(w, 0x10);
    if (ov99_021E5BB4(P(w, 0), U32(w, 0x88))) {
        ov98_0221EBD8(P(w, 0x10), 13, 1, 0);
    } else {
        FillWindowPixelBuffer((R99 *)P(obj, 4) + 0xd0, 0);
        ScheduleWindowCopyToVram((R99 *)P(obj, 4) + 0xd0);
    }
}

void ov99_021E6250(R99 *w) {
    volatile u8 *base = (volatile u8 *)0x027e0000;
    SpriteSystem_TransferOam(w);
    DoScheduledBgGpuUpdates(P(w, 4));
    *(volatile u32 *)(base + 0x3ff8) |= 1;
}
