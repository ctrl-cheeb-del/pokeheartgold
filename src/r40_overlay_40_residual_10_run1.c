#include "global.h"

#include "sprite_system.h"

void GF_AssertFail(void);
typedef struct FrontierCard FrontierCard;
u32 sub_020315D0(FrontierCard *);
u32 sub_02031700(FrontierCard *);
extern u32 ov40_02244FF0[][4];

void ov40_0222E624(void *, void *);
u32 ov40_0222E658(int, int);
void ov40_0222E690(void *, void *);

void ov40_0222E624(void *p, void *owner) {
    SpriteManager_UnloadCharObjById(*(void **)((u8 *)owner + 0x1C), 0x2869F);
    SpriteManager_UnloadPlttObjById(*(void **)((u8 *)owner + 0x1C), 0x2869F);
    SpriteManager_UnloadCellObjById(*(void **)((u8 *)owner + 0x1C), 0x2869F);
    SpriteManager_UnloadAnimObjById(*(void **)((u8 *)owner + 0x1C), 0x2869F);
    Sprite_DeleteAndFreeResources(*(ManagedSprite **)((u8 *)p + 8));
}

u32 ov40_0222E658(int value, int kind) {
    if (value > 16 || value < 0) {
        GF_AssertFail();
        value = 0;
    }
    if (kind == 4) {
        return value + 0x13C;
    }
    if (kind >= 5) {
        return 0;
    }
    return ov40_02244FF0[value][kind];
}

void ov40_0222E690(void *p, void *work) {
    ManagedSpriteTemplate template;
    PaletteData *palette;
    int charFile = 14;
    int palFile = 13;
    int mode = sub_020315D0(*(FrontierCard **)p);
    SpriteSystem *system = *(SpriteSystem **)((u8 *)work + 0x18);
    SpriteManager *manager = *(SpriteManager **)((u8 *)work + 0x1C);
    palette = *(PaletteData **)((u8 *)work + 0x28);

    if (*(void **)((u8 *)work + 0x86C) == NULL) {
        if (mode == 1) {
            palFile = 15;
            charFile = 16;
        }
    } else {
        int value = sub_02031700(*(FrontierCard **)p);
        if (value >= 16) {
            value = 0;
        }
        palFile = ov40_0222E658(value, 2);
        charFile = ov40_0222E658(value, 3);
    }

    SpriteSystem_LoadPaletteBuffer(palette, (PaletteBufferId)2, system, manager, (NarcId)0xB3, palFile, FALSE, 1, 1, 0x2869F);
    SpriteSystem_LoadCellResObj(system, manager, (NarcId)0xB3, 9, FALSE, 0x2869F);
    SpriteSystem_LoadAnimResObj(system, manager, (NarcId)0xB3, 10, FALSE, 0x2869F);
    SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType(system, manager, (NarcId)0xB3, charFile, FALSE, 1, 0x2869F);

    template.x = 40;
    template.y = 60;
    template.z = 0;
    template.animation = 0;
    template.drawPriority = 0;
    template.pal = 0;
    template.vram = (NNS_G2D_VRAM_TYPE)1;
    template.resIdList[0] = 0x2869F;
    template.resIdList[1] = 0x2869F;
    template.resIdList[2] = 0x2869F;
    template.resIdList[3] = 0x2869F;
    template.resIdList[4] = -1;
    template.resIdList[5] = -1;
    template.bgPriority = 0;
    template.vramTransfer = 0;
    *(ManagedSprite **)((u8 *)p + 8) = SpriteSystem_NewSprite(*(SpriteSystem **)((u8 *)work + 0x18), *(SpriteManager **)((u8 *)work + 0x1C), &template);
    ManagedSprite_SetAnim(*(ManagedSprite **)((u8 *)p + 8), 1);
    ManagedSprite_TickFrame(*(ManagedSprite **)((u8 *)p + 8));
}
