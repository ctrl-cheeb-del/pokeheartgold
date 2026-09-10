#include "overlay68_helpers_internal.h"

void ov68_021E6E84(MoveRelearner *d) {
    u32 i;
    for (i = 0; i < 12; i++) {
        Sprite_DeleteAndFreeResources(d->sprites[i]);
    }
    SpriteSystem_FreeResourcesAndManager(d->unk_11C, d->unk_120);
    SpriteSystem_Free(d->unk_11C);
}
