#include "overlay_98_helpers_internal.h"

void ov98_0221E9FC(ManagedSprite *sprite, void *data, u32 size) {
    NNS_G2D_VRAM_TYPE type = Sprite_GetVramType(sprite->sprite);
    u32 address = NNS_G2dGetImageLocation(Sprite_GetImageProxy(sprite->sprite), type);

    DC_FlushRange(data, size);
    switch (type) {
    case NNS_G2D_VRAM_TYPE_2DMAIN:
        GX_LoadOBJ(data, address, size);
        break;
    case NNS_G2D_VRAM_TYPE_2DSUB:
        GXS_LoadOBJ(data, address, size);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}
