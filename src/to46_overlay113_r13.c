#include "global.h"

#include "sprite_system.h"

typedef struct UnownReportWork {
    u8 pad_000[0xAC];
    SpriteSystem *spriteSystem;
    SpriteManager *unk_B0;
    SpriteManager *spriteManager;
    Sprite *sprites[3];
    ManagedSprite *icons[14];
    NARC *narc;
} UnownReportWork;

extern void Sprite_DeleteAndFreeResources(ManagedSprite *sprite);
extern void Sprite_Delete(Sprite *sprite);
extern u32 GetMonIconNaixEx(u32 species, BOOL isEgg);
extern u8 GetMonIconPaletteEx(u32 species, u32 form, u32 isEgg);
extern const UnmanagedSpriteTemplate ov113_021E6CF8[];
void ov113_021E69CC(UnownReportWork *work);
void ov113_021E6AB0(UnownReportWork *work);
void ov113_021E6AE8(UnownReportWork *work, int icon);

void ov113_021E69CC(UnownReportWork *work) {
    ManagedSpriteTemplate template;
    int i;
    int y;
    int upperY;

    for (i = 0; i < 3; i++) {
        work->sprites[i] = SpriteSystem_CreateSpriteFromResourceHeader(work->spriteSystem, work->unk_B0, &ov113_021E6CF8[i]);
        Sprite_SetDrawFlag(work->sprites[i], TRUE);
        Sprite_SetAnimActiveFlag(work->sprites[i], TRUE);
        Sprite_SetPriority(work->sprites[i], 2);
    }

    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgPriority = 1;
    {
        int pal = GetMonIconPaletteEx(201, 0, 0);
        i = 0;
        template.pal = pal;
    }
    template.vramTransfer = i;
    template.x = 40;
    template.resIdList[1] = 1;
    template.resIdList[2] = 1;
    template.resIdList[3] = 1;
    template.resIdList[4] = -1;
    template.resIdList[5] = -1;
    upperY = 29;
    y = i;
    for (; i < 14; i++) {
        if (i < 7) {
            template.y = upperY;
            template.vram = (NNS_G2D_VRAM_TYPE)2;
        } else {
            template.y = y - 155;
            template.vram = (NNS_G2D_VRAM_TYPE)1;
        }
        template.resIdList[0] = i + 1;
        work->icons[i] = SpriteSystem_NewSprite(work->spriteSystem, work->spriteManager, &template);
        ManagedSprite_SetDrawFlag(work->icons[i], FALSE);
        upperY += 24;
        y += 24;
    }
}

void ov113_021E6AB0(UnownReportWork *work) {
    int i;

    for (i = 0; i < 14; i++) {
        if (work->icons[i] != NULL) {
            Sprite_DeleteAndFreeResources(work->icons[i]);
        }
    }
    for (i = 0; i < 3; i++) {
        if (work->sprites[i] != NULL) {
            Sprite_Delete(work->sprites[i]);
        }
    }
}

void ov113_021E6AE8(UnownReportWork *work, int icon) {
    u32 fileId = GetMonIconNaixEx(201, FALSE);
    sub_0200E2B8(work->spriteSystem, work->spriteManager, work->narc, fileId, FALSE, icon + 1);
}
