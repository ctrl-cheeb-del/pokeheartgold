#include "overlay57_vram_helpers_private.h"

void ov57_02238AC0(void *work) {
    s32 i;
    u8 *p;
    i = 0;
    p = work;
    for (; i < 8; i++, p += 4) {
        SpriteManager_UnloadCharObjById(R20_PTR(work, 0xe0), 0x61a8 + i);
        Sprite_DeleteAndFreeResources(R20_PTR(p, 0x414));
    }
}

void ov57_02238AF0(void *work, s32 amount) {
    s16 x = amount * 0x38;
    s16 y = -(amount << 4);
    s32 i;
    u8 *p = work;
    for (i = 0; i < 8; i++, p += 0x10) {
        if (R20_PTR(p, 0x34c) != NULL) {
            ManagedSprite_OffsetPositionXY(R20_PTR(p, 0x354), x, y);
        }
    }
}

void ov57_02238B28(void) {
    GF_3DVramMan_Create(0x34, 0, 2, 0, 2, ov57_02238B48);
}
