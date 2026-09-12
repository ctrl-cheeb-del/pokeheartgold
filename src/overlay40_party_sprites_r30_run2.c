#include "overlay40_party_sprites_r30_private.h"

void ov40_02237548(Ov40PartySpriteWork *work, int value) {
    Ov40PartySpriteData *data = *(Ov40PartySpriteData **)(work->raw + 0x860);
    void *pic = *(void **)((u8 *)data + 0x32c);

    if (pic != NULL) {
        Pokepic_SetAttr(pic, 6, value);
    }
}
