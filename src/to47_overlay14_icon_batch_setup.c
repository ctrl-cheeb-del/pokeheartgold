#include "to47_overlay14_icon_batch_setup_private.h"

void ov14_021F2C84(BoxSpriteWork *work) {
    u32 i;

    for (i = 0; i < 36; i++) {
        SpriteSystem_LoadCharResObj(work->spriteSystem, work->spriteManager, NARC_a_0_1_9, 0x4E, TRUE, 1, 0xC0F9 + i);
    }
    SpriteSystem_LoadPlttResObj(work->spriteSystem, work->spriteManager, NARC_poketool_icongra_poke_icon, sub_02074490(), FALSE, 3, 1, 0xC0F9);
    SpriteSystem_LoadCellResObj(work->spriteSystem, work->spriteManager, NARC_poketool_icongra_poke_icon, sub_0207449C(), FALSE, 0xC0F9);
    SpriteSystem_LoadAnimResObj(work->spriteSystem, work->spriteManager, NARC_poketool_icongra_poke_icon, sub_020744A8(), FALSE, 0xC0F9);
}

void ov14_021F2D1C(BoxSpriteWork *work) {
    ManagedSpriteTemplate template;
    ManagedSpriteTemplate base;
    int priority;
    u32 i;
    u8 *slot;

    i = 0;
    priority = 0;
    slot = (u8 *)work;
    base = ov14_021F810C;
    for (; i < 36; i++) {
        template = base;
        template.x += 24 * (i % 6);
        template.y += 24 * (i / 6);
        template.drawPriority = 0x74 - priority;
        template.resIdList[0] = 0xC0F9 + i;
        *(ManagedSprite **)(slot + 0x360) = SpriteSystem_NewSprite(work->spriteSystem, work->spriteManager, &template);
        U8(work, 0x4094 + i) = i + 0x19;
        priority += 2;
        slot += 4;
    }
}
