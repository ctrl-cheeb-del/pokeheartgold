#include "to47_overlay18_pokedex_area_ui_03_private.h"

void ov18_021F1FDC(void *p, int idx) {
    ManagedSpriteTemplate template = ov18_021FA41C;

    *(ManagedSprite **)((u8 *)p + 0x670 + idx * 4) = SpriteSystem_NewSpriteWithYOffset(
        *(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), &template, 0x200000);
    template.resIdList[0] = 0xC595;
    *(ManagedSprite **)((u8 *)p + 0x678 + idx * 4) = SpriteSystem_NewSpriteWithYOffset(
        *(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), &template, 0x200000);
    template.x += 0x31;
    template.resIdList[0] = 0xC594;
    *(ManagedSprite **)((u8 *)p + 0x674 + idx * 4) = SpriteSystem_NewSpriteWithYOffset(
        *(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), &template, 0x200000);
    template.resIdList[0] = 0xC596;
    *(ManagedSprite **)((u8 *)p + 0x67C + idx * 4) = SpriteSystem_NewSpriteWithYOffset(
        *(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), &template, 0x200000);
}
