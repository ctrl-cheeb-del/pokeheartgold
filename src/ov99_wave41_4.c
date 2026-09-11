#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

void ov99_021E5F74(R99 *w) {
    s32 raw, x;
    u8 i;
    if (U32(w, 0x8c) == 0) {
        return;
    }
    raw = Bg_GetXpos(P(w, 4), 2);
    x = raw >> 2;
    if (raw == x) {
        x = 0;
    }
    ScheduleSetBgPosText(P(w, 4), 2, 0, x);
    ScheduleSetBgPosText(P(w, 4), 5, 0, x);
    for (i = 0; i < 6; i++) {
        const Ov99Pos *p = &ov99_021E9690[i];
        ManagedSprite_SetPositionXY(P(w, 0x18 + p->sprite * 4), (s16)(p->x - x), (s16)p->y);
    }
    if (x == 0) {
        U32(w, 0x8c) = 0;
    }
}

void ov99_021E5FE8(R99 *w, u32 i) {
    if (ov99_021E5BB4(P(w, 0), i)) {
        ov99_021E5EB4(w, i, U32(w, 0x84));
    } else {
        BgClearTilemapBufferAndCommit(P(w, 4), 2);
        BgClearTilemapBufferAndCommit(P(w, 4), 5);
    }
}

void ov99_021E6018(R99 *w) {
    ov98_0221EC08(P(w, 0x10), 0, 2, 1, 0);
    ov98_0221EBEC(P(w, 0x10), 2, 0, 1, 0, 4);
    ov98_0221EBD8(P(w, 0x10), 11, 7, 0);
}

void ov99_021E6050(R99 *w, u32 i) {
    ov99_021E6188(w);
    ov99_021E607C(w, i);
    ov99_021E6144(w, ov99_021E5BB4(P(w, 0), i));
    ov99_021E6218(w);
}
