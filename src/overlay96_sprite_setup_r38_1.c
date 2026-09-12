#include "overlay96_r38_private.h"

void ov96_021EC490(void *raw) {
    Ov96R38Work *work = raw;
    Ov96R38Counts counts = ov96_0221AF88;
    Ov96R38Oam oam = ov96_0221B010;
    Ov96R38Transfer transfer = ov96_0221AF74;

    transfer.values[0] = 0x80;
    work->spriteSystem = SpriteSystem_Alloc(*(u32 *)work);
    work->spriteManager = SpriteManager_New(work->spriteSystem);
    SpriteSystem_Init(work->spriteSystem, &oam, &transfer, 0x20);
    SpriteSystem_InitSprites(work->spriteSystem, work->spriteManager, 0x80);
    SpriteSystem_InitManagerWithCapacities(work->spriteSystem, work->spriteManager, &counts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(work->spriteSystem), 0, 0x20c000);
}

void ov96_021EC51C(void *raw) {
    Ov96R38Work *work = raw;
    u8 i;

    for (i = 0; i < 26; i++) {
        if (work->sprites[i] != NULL) {
            Sprite_DeleteAndFreeResources(work->sprites[i]);
            work->sprites[i] = NULL;
        }
    }
    SpriteSystem_FreeResourcesAndManager(work->spriteSystem, work->spriteManager);
    SpriteSystem_Free(work->spriteSystem);
}

void ov96_021EC550(void *raw) {
    Ov96R38Work *work = raw;
    Ov96R38SpriteTemplate template = { 0 };
    int i;
    int x = 0x20;
    u8 *cursor = raw;

    for (i = 0; i < 5;) {
        template.resources[0] = i + 0x64;
        template.resources[1] = i + 0x64;
        template.resources[2] = 0x64;
        template.resources[3] = 0x64;
        template.vram = 2;
        template.bgPriority = 1;
        template.drawPriority = 1;
        template.x = x;
        template.y = 0x88;
        if (i == 4) {
            template.x = 0x80;
            template.y = 0x70;
        }
        PTR(cursor, 0x20) = SpriteSystem_NewSpriteWithYOffset(work->spriteSystem, work->spriteManager, &template, 0x20c000);
        ManagedSprite_SetAnimateFlag(PTR(cursor, 0x20), 1);
        i++;
        x += 0x40;
        cursor += 4;
    }
}
