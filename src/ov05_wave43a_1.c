#include "ov05_wave43_private.h"
typedef struct T12 {
    u32 a[6];
} T12;

void ov05_0221E2D8(R12 *w) {
    void *n = NARC_New(0x14, U32(P(w, 0), 0x24));
    u32 i;
    R12 *p;
    SpriteSystem_LoadPlttResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, sub_02074490(), 0, 3, 1, 0xb808);
    SpriteSystem_LoadCellResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, sub_02074498(), 0, 0xb809);
    SpriteSystem_LoadAnimResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, sub_020744A4(), 0, 0xb809);
    i = 0;
    p = w;
    do {
        SpriteSystem_LoadCharResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, U32(p, 0x214), 0, 1, 0xb809 + i);
        i++;
        p += 24;
    } while (i < 6);
    NARC_Delete(n);
}
