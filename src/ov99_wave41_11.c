#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

void ov99_021E69D8(R99 *w) {
    GfGfxLoader_GXLoadPalFromOpenNarc(P(w, 8), 0x38, 0, 0, 0x40, U32(w, 0xc));
    GfGfxLoader_LoadCharDataFromOpenNarc(P(w, 8), 0x39, P(w, 4), 0, 0, 0, 1, U32(w, 0xc));
    GfGfxLoader_LoadScrnDataFromOpenNarc(P(w, 8), 0x3a, P(w, 4), 0, 0, 0, 1, U32(w, 0xc));
    GfGfxLoader_GXLoadPalFromOpenNarc(P(w, 8), 0x3b, 4, 0, 0x40, U32(w, 0xc));
    GfGfxLoader_LoadCharDataFromOpenNarc(P(w, 8), 0x3c, P(w, 4), 4, 0, 0, 1, U32(w, 0xc));
    GfGfxLoader_LoadScrnDataFromOpenNarc(P(w, 8), 0x3d, P(w, 4), 4, 0, 0, 1, U32(w, 0xc));
}

void ov99_021E6A70(R99 *w) {
    u8 i;
    NARC_Delete(P(w, 8));
    for (i = 0; i < 4; i++) {
        FreeBgTilemapBuffer(P(w, 4), ov99_021E9D88[i]);
    }
    Heap_Free(P(w, 4));
}
