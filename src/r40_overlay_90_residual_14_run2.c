#include "global.h"

#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "overlay90_resource_internal.h"

extern void sub_0200F478(void *);
extern void ov90_0225A65C(NARC *, int, enum HeapID);
extern void ov90_0225A2B0(void *, void *, void *, int, NARC *, enum HeapID);
void ov90_02259570(void *, int);
void ov90_022596C8(void *, enum HeapID);

typedef struct Ov90TextSlots {
    u8 filler[0x2c];
    void *slots[2];
} Ov90TextSlots;

void ov90_022596C8(void *work, enum HeapID heapId) {
    u8 *raw = work;
    NARC *narc = NARC_New((NarcId)0xc8, heapId);

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 4, (enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0, 0x120, heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 6, *(BgConfig **)(raw + 0x30), (GFBgLayer)1, 0, 0, FALSE, heapId);
    *(void **)(raw + 0x1fc) = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 9, FALSE, (NNSG2dScreenData **)(raw + 0x200), heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 8, *(BgConfig **)(raw + 0x30), (GFBgLayer)3, 0, 0, FALSE, heapId);
    ov90_0225A65C(narc, *(u16 *)(raw + 4), heapId);
    *(Ov90ResRec **)(raw + 0x1c8) = ov90_02258E54((Ov90ResWork *)(raw + 0x1b0), (int)narc, 0xb, 5, 0xc, 0xd, 0xe, 0x1388, heapId);
    ov90_0225A2B0(raw + 0x1cc, raw + 0x30, raw + 0x3c, *(u16 *)(raw + 4), narc, heapId);
    NARC_Delete(narc);
}
