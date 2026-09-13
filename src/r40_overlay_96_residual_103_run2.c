#include "r40_overlay_96_residual_103_private.h"

void ov96_022101D0(void *work) {
    s32 i;
    s32 j;
    u8 *entry;

    i = 0;
    entry = work;
    for (; i < 12; i++, entry += 0x1c) {
        if (PTR(entry, 0x3c) == NULL) {
            GF_AssertFail();
        }
        Sprite_DeleteAndFreeResources(PTR(entry, 0x3c));
        if (PTR(entry, 0x44) != NULL) {
            SysTask_Destroy(PTR(entry, 0x44));
        }
    }
    i = 0;
    entry = (u8 *)work + 4;
    for (; i < 2; i++, entry += 0x1c) {
        u8 *sprite;
        j = 0;
        sprite = entry;
        for (; j < 2; j++, sprite += 4) {
            Sprite_DeleteAndFreeResources(PTR(sprite, 0));
            Sprite_DeleteAndFreeResources(PTR(sprite, 8));
        }
        Sprite_DeleteAndFreeResources(PTR(entry, 0x10));
        Sprite_DeleteAndFreeResources(PTR(entry, 0x14));
    }
}
