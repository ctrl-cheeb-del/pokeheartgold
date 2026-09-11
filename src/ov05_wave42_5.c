#include "ov05_wave42_private.h"
typedef struct T12 {
    u32 a[6];
} T12;

void ov05_0221E390(R12 *w) {
    void *n = NARC_New(0x15, U32(P(w, 0), 0x24));
    SpriteSystem_LoadCharResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 0x14, 0, 1, 0xb80f);
    SpriteSystem_LoadPlttResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 0x15, 0, 1, 1, 0xb809);
    SpriteSystem_LoadCellResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 0x13, 0, 0xb80a);
    SpriteSystem_LoadAnimResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 0x12, 0, 0xb80a);
    NARC_Delete(n);
}

void ov05_0221E42C(R12 *w) {
    void *n = NARC_New(0x27, U32(P(w, 0), 0x24));
    SpriteSystem_LoadCharResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 0x40, 0, 1, 0xb810);
    SpriteSystem_LoadPlttResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 0x41, 0, 1, 1, 0xb80a);
    SpriteSystem_LoadCellResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 0x3f, 0, 0xb80b);
    SpriteSystem_LoadAnimResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 0x3e, 0, 0xb80b);
    NARC_Delete(n);
}

void ov05_0221E4C8(R12 *w) {
    void *n = NARC_New(0x15, U32(P(w, 0), 0x24));
    SpriteSystem_LoadCharResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 2, 0, 1, 0xb811);
    SpriteSystem_LoadPlttResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 8, 0, 2, 1, 0xb80b);
    SpriteSystem_LoadCellResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 1, 0, 0xb80c);
    SpriteSystem_LoadAnimResObjFromOpenNarc(P(w, 0x190), P(w, 0x194), n, 0, 0, 0xb80c);
    NARC_Delete(n);
}
