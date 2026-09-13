#include "global.h"

#include "gf_gfx_loader.h"
#include "pokemon_icon_idx.h"
#include "sprite_system.h"

typedef struct Ov111WorkR5 {
    u32 heapId;
    u8 pad04[8];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    u8 pad14[8];
    NARC *narc;
    u8 pad20[8];
    u8 iconPalette;
} Ov111WorkR5;

extern const ManagedSpriteTemplate ov111_021E6C34;
extern const ManagedSpriteTemplate ov111_021E6C00;

void ov111_021E6180(Ov111WorkR5 *work);
void ov111_021E6268(ManagedSprite *sprite, Pokemon *mon, int paletteOffset, int heapId);
void ov111_021E62E0(ManagedSprite *sprite, void *data, u32 size);
ManagedSprite *ov111_021E6330(SpriteSystem *system, SpriteManager *manager, s16 x, s16 y, u8 animation, u8 priority);
ManagedSprite *ov111_021E6380(SpriteSystem *system, SpriteManager *manager, s16 x, s16 y, u8 resourceSet);

void ov111_021E6180(Ov111WorkR5 *work) {
    int i;
    NARC *narc;
    SpriteSystem *system = work->spriteSystem;
    SpriteManager *manager = work->spriteManager;

    SpriteSystem_LoadPlttResObjFromOpenNarc(system, manager, work->narc, 5, FALSE, 2, 1, 0);
    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, work->narc, 6, TRUE, 1, 0);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, work->narc, 7, TRUE, 0);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, work->narc, 8, TRUE, 0);
    narc = NARC_New((NarcId)0x14, (enum HeapID)work->heapId);
    for (i = 0; i < 2; i++) {
        SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, work->narc, 9, FALSE, 1, i + 1);
    }
    work->iconPalette = SpriteSystem_LoadPlttResObjFromOpenNarc(system, manager, narc, sub_02074490(), FALSE, 3, 1, 1);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, narc, sub_0207449C(), FALSE, 1);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, narc, sub_020744A8(), FALSE, 1);
    NARC_Delete(narc);
}

void ov111_021E6268(ManagedSprite *sprite, Pokemon *mon, int paletteOffset, int heapId) {
    NNSG2dCharacterData *charData;
    u8 palette;
    NARC *narc = NARC_New((NarcId)0x14, (enum HeapID)heapId);
    void *raw = GfGfxLoader_GetCharDataFromOpenNarc(narc, Pokemon_GetIconNaix(mon), FALSE, &charData, (enum HeapID)heapId);

    ov111_021E62E0(sprite, charData->pRawData, 0x400);
    Heap_Free(raw);
    palette = paletteOffset + Pokemon_GetIconPalette(mon);
    ManagedSprite_SetPaletteOverride(sprite, palette);
    ManagedSprite_SetAnim(sprite, 1);
    ManagedSprite_SetAnimSpeed(sprite, FX32_ONE);
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
    NARC_Delete(narc);
}

void ov111_021E62E0(ManagedSprite *sprite, void *data, u32 size) {
    NNS_G2D_VRAM_TYPE vram = Sprite_GetVramType(sprite->sprite);
    u32 location = NNS_G2dGetImageLocation(Sprite_GetImageProxy(sprite->sprite), vram);

    DC_FlushRange(data, size);
    switch (vram) {
    case NNS_G2D_VRAM_TYPE_2DMAIN:
        GX_LoadOBJ(data, location, size);
        break;
    case NNS_G2D_VRAM_TYPE_2DSUB:
        GXS_LoadOBJ(data, location, size);
        break;
    default:
        GF_AssertFail();
        break;
    }
}

ManagedSprite *ov111_021E6330(SpriteSystem *system, SpriteManager *manager, s16 x, s16 y, u8 animation, u8 priority) {
    ManagedSpriteTemplate template = ov111_021E6C34;
    ManagedSprite *sprite;

    template.x = x;
    template.y = y;
    template.drawPriority = priority;
    template.animation = animation;
    sprite = SpriteSystem_NewSpriteWithYOffset(system, manager, &template, 0x20C000);
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
    return sprite;
}

ManagedSprite *ov111_021E6380(SpriteSystem *system, SpriteManager *manager, s16 x, s16 y, u8 resourceSet) {
    ManagedSpriteTemplate template = ov111_021E6C00;

    if (resourceSet >= 2) {
        GF_AssertFail();
    }
    template.resIdList[0] = resourceSet + 1;
    template.x = x;
    template.y = y;
    return SpriteSystem_NewSpriteWithYOffset(system, manager, &template, 0x20C000);
}
