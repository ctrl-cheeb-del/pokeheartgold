#include "ov57_wave42_private.h"

void ov57_02238044(u8 *w, s32 selected) {
    s32 i;
    u8 *p = w;
    for (i = 0; i < 8; i++, p += 0x10) {
        if (*(u32 *)(p + 0x34C) == 1) {
            if (i == selected) {
                ManagedSprite_SetDrawPriority(*(ManagedSprite **)(p + 0x354), 0);
            } else {
                u32 priority = ManagedSprite_GetDrawPriority(*(ManagedSprite **)(p + 0x354));
                if (priority == 0) {
                    ManagedSprite_SetDrawPriority(*(ManagedSprite **)(p + 0x354), priority + 1);
                } else {
                    ManagedSprite_SetDrawPriority(*(ManagedSprite **)(p + 0x354), priority + 2);
                }
            }
        }
    }
}

void ov57_0223809C(u8 *w, void *narc, s32 i) {
    void *spriteSystem = *(void **)(w + 0xDC);
    void *spriteManager = *(void **)(w + 0xE0);
    SpriteSystem_LoadPaletteBuffer(*(void **)(w + 0xE8), 3, spriteSystem, spriteManager, 0x57, 6, FALSE, 1, 2, 0x520E);
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, 0x57, sub_02091054((u32)narc), TRUE, 2, i + 0x4E20);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, 0x57, 0x26, TRUE, 0x5616);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, 0x57, 0x24, TRUE, 0x59FC);
}
