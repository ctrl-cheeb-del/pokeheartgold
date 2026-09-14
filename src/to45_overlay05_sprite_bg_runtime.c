#include "to45_overlay05_sprite_bg_runtime_private.h"

void ov05_0221CD24(Ov05R8WorkInit *work, const void *capacities, u32 count) {
    Ov05R8OamConfig oam;
    Ov05R8TransferConfig transfer;

    GF_CreateVramTransferManager(0x40, work->root->heapId);
    work->spriteSystem = SpriteSystem_Alloc(work->root->heapId);
    work->spriteManager = SpriteManager_New(work->spriteSystem);
    oam = ov05_0221EBE0;
    transfer = ov05_0221EAAC;
    transfer.values[0] = count;
    SpriteSystem_Init(work->spriteSystem, &oam, &transfer, 0x10);
    SpriteSystem_InitSprites(work->spriteSystem, work->spriteManager, count);
    SpriteSystem_InitManagerWithCapacities(work->spriteSystem, work->spriteManager, capacities);
    GfGfx_EngineATogglePlanes(0x10, TRUE);
}

void ov05_0221CDC4(void *work, const Ov05R8SpriteSource *source) {
    Ov05R8SpriteTemplate template;

    template.field00 = 0;
    template.field02 = 0;
    template.field04 = 0;
    template.field06 = 0;
    template.field08 = source->field14;
    template.field0C = source->field18;
    template.field10 = 1;
    template.field14 = source->field00;
    template.field18 = source->field04;
    template.field1C = source->field08;
    template.field20 = source->field0C;
    template.field2C = source->field10;
    template.field30 = 0;
    SpriteSystem_NewSprite(PTR_AT(work, 0x190), PTR_AT(work, 0x194), &template);
}

void ov05_0221CE0C(void *work) {
    u32 i;
    Ov05R8WorkSprites *sprites = work;

    for (i = 0; i < sprites->count; i++) {
        Sprite_DeleteAndFreeResources(sprites->sprites[i]);
    }
    SpriteSystem_FreeResourcesAndManager(PTR_AT(work, 0x190), PTR_AT(work, 0x194));
    SpriteSystem_Free(PTR_AT(work, 0x190));
}

void ov05_0221CE50(void *work) {
    u16 i;
    Ov05R8WorkSprites *sprites = work;

    for (i = 0; i < sprites->count; i++) {
        Sprite_UpdateAnim(PTR_AT(sprites->sprites[i], 0), FX32_ONE);
    }
}

void ov05_0221CE88(void *work) {
    vu32 *irqBase = (vu32 *)0x027E0000;

    DoScheduledBgGpuUpdates(PTR_AT(work, 0xC));
    PaletteData_PushTransparentBuffers(PTR_AT(work, 8));
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    irqBase[0x3FF8 / sizeof(u32)] |= 1;
}

void ov05_0221CEB8(void *work, int mode, int shifted) {
    Ov05R8GraphicsModes modes;
    Ov05R8BgTemplate bg3;
    Ov05R8BgTemplate bg2;
    Ov05R8BgTemplate bg1;

    U32_AT(work, 0xBA8) = mode;
    modes = ov05_0221EA78;
    modes.values[3] = mode;
    SetBothScreensModesAndDisable(&modes);

    bg3 = ov05_0221EB1C;
    InitBgFromTemplate(PTR_AT(work, 0xC), 3, &bg3, 0);
    BgClearTilemapBufferAndCommit(PTR_AT(work, 0xC), 3);
    ScheduleSetBgPosText(PTR_AT(work, 0xC), 3, 0, 0x100);

    bg2 = ov05_0221EB54;
    InitBgFromTemplate(PTR_AT(work, 0xC), 2, &bg2, 0);
    BgClearTilemapBufferAndCommit(PTR_AT(work, 0xC), 2);
    ScheduleSetBgPosText(PTR_AT(work, 0xC), 2, 0, -0x100);

    bg1 = ov05_0221EB70;
    InitBgFromTemplate(PTR_AT(work, 0xC), 1, &bg1, 0);
    BgClearTilemapBufferAndCommit(PTR_AT(work, 0xC), 1);
    GfGfx_EngineATogglePlanes(2, FALSE);
    if (shifted == 1) {
        BgSetPosTextAndCommit(PTR_AT(work, 0xC), 1, 3, 0x18);
    }
    if (mode == 0) {
        Ov05R8BgTemplate bg0 = ov05_0221EBA8;

        InitBgFromTemplate(PTR_AT(work, 0xC), 0, &bg0, 0);
        BgClearTilemapBufferAndCommit(PTR_AT(work, 0xC), 0);
        if (U32_AT(work, 0xBC8) == 1) {
            GfGfx_EngineATogglePlanes(1, TRUE);
        } else {
            GfGfx_EngineATogglePlanes(1, FALSE);
        }
    }
}
