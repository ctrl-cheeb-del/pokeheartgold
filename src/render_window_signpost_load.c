#include "gf_gfx_loader.h"
#include "render_window_signpost_private.h"

void LoadMapSignpostFrameAndGraphic(BgConfig *bgConfig, u8 bgId, u16 baseTile, u8 plttNum, u8 type, u16 map, enum HeapID heapId) {
    void *raw;
    NNSG2dPaletteData *palette;

    GfGfxLoader_LoadCharData((NarcId)0x24, 0, bgConfig, (GFBgLayer)bgId, baseTile, 0x3c0, FALSE, heapId);
    raw = AllocAndReadWholeNarcMemberByIdPair((NarcId)0x24, 1, heapId);
    NNS_G2dGetUnpackedPaletteData(raw, &palette);
    BG_LoadPlttData(bgId, (u8 *)palette->pRawData + type * 0x20, 0x20, plttNum << 5);
    Heap_FreeExplicit(heapId, raw);
    {
        u8 typeLocal = *(volatile u8 *)&type;
        if (typeLocal <= 1) {
            sub_0200EC84(bgConfig, bgId, baseTile + 0x1e, typeLocal, map, heapId);
        }
    }
}
