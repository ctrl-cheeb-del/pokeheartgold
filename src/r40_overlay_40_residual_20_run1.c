#include "r40_overlay_40_residual_20_private.h"

void ov40_0222FF48(void *work, u32 resourceOffset, void *sprite) {
    if (sprite != NULL) {
        SpriteManager_UnloadCharObjById(PTR_AT(work, 0x1c), 0x186a0 + resourceOffset);
        Sprite_DeleteAndFreeResources(sprite);
    }
}
