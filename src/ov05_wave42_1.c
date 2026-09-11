#include "ov05_wave42_private.h"
typedef struct T12 {
    u32 a[6];
} T12;

void ov05_0221DC60(R12 *w) {
    void *n = NARC_New(0x15, U32(P(w, 0), 0x24));
    void *raw;
    NNSG2dPaletteData *pltt;
    GfGfxLoader_LoadCharDataFromOpenNarc(n, 15, P(w, 0xc), 3, 0, 0, FALSE, U32(P(w, 0), 0x24));
    GfGfxLoader_LoadScrnDataFromOpenNarc(n, 17, P(w, 0xc), 3, 0, 0, FALSE, U32(P(w, 0), 0x24));
    raw = NARC_AllocAndReadWholeMember(n, 16, U32(P(w, 0), 0x24));
    NNS_G2dGetUnpackedPaletteData(raw, &pltt);
    BG_LoadPlttData(3, pltt->pRawData, (u16)pltt->szByte, 0);
    memcpy(w + 0x4e4, (u8 *)pltt->pRawData + 0x60, 0x60);
    Heap_Free(raw);
    sub_0207CAAC(U32(P(w, 0), 0x24), (u16 *)(w + 0x2a4), (u16 *)(w + 0x364), (u16 *)(w + 0x424));
    NARC_Delete(n);
}
