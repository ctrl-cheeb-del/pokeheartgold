#include "overlay02_effect_resources_r17_private.h"

void ov02_0224A810(void *p, void *narc) {
    AddCharResObjFromOpenNarc(PTR(p, 0x19c), narc, 9, FALSE, 3, 1, HEAP_ID_FIELD1);
}

void ov02_0224A834(void *p, void *src) {
    SpriteResource *res = SpriteResourceCollection_Find(PTR(p, 0x19c), 3);
    void *proxy = SpriteTransfer_GetCharProxy(res);
    u32 dst = NNS_G2dGetImageLocation(proxy, NNS_G2D_VRAM_TYPE_2DMAIN);
    DC_FlushRange(src, 0xc80);
    GX_LoadOBJ(src, dst, 0xc80);
}

void ov02_0224A868(void *p, void *narc) {
    AddPlttResObjFromOpenNarc(PTR(p, 0x1a0), narc, 6, FALSE, 3, 1, 1, HEAP_ID_FIELD1);
}

void ov02_0224A88C(void *p, void *src) {
    SpriteResource *charRes = SpriteResourceCollection_Find(PTR(p, 0x19c), 3);
    void *charProxy = SpriteTransfer_GetCharProxy(charRes);
    SpriteResource *plttRes = SpriteResourceCollection_Find(PTR(p, 0x1a0), 3);
    void *plttProxy = SpriteTransfer_GetPaletteProxy(plttRes, charProxy);
    u32 dst = NNS_G2dGetImagePaletteLocation(plttProxy, NNS_G2D_VRAM_TYPE_2DMAIN);
    DC_FlushRange(src, 0x20);
    GX_LoadOBJPltt(src, dst, 0x20);
}
