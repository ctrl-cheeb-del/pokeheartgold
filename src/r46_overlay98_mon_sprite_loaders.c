#include "r46_overlay98_mon_sprite_loaders_private.h"

#define OV98_MON_PIC_BUFFER_SIZE 0xC80

void ov98_0221E7E8(ManagedSprite *sprite, const Ov98MonInfo *mon, BOOL isMain, BOOL grayscale, enum HeapID heapId) {
    PokepicTemplate pokepic;
    UnkStruct_02014E30 rect;
    void *charBuf;

    if (mon->species == SPECIES_NONE) {
        ManagedSprite_SetDrawFlag(sprite, FALSE);
        return;
    }

    GetMonSpriteCharAndPlttNarcIdsEx(&pokepic, mon->species, mon->gender, MON_PIC_FACING_FRONT, mon->shiny, mon->form, mon->personality);
    rect = ov98_0221F19C;
    charBuf = Heap_AllocAtEnd(heapId, OV98_MON_PIC_BUFFER_SIZE);
    sub_02014510((NarcId)pokepic.narcID, pokepic.charDataID, heapId, &rect, charBuf, mon->personality, FALSE, MON_PIC_FACING_FRONT, mon->species);
    ov98_0221E9FC(sprite, charBuf, OV98_MON_PIC_BUFFER_SIZE);
    ov98_0221EA4C(sprite, (NarcId)pokepic.narcID, pokepic.palDataID, isMain, grayscale, heapId);
    ManagedSprite_SetDrawFlag(sprite, TRUE);
    Heap_Free(charBuf);
}

void ov98_0221E8A8(Ov98SpriteContext *spriteSys, const int *resIds, int count, int screen, BOOL flag) {
    SpriteSystem *spriteSystem = spriteSys->spriteSystem;
    SpriteManager *spriteManager = spriteSys->spriteManager;
    int fileId;
    u32 cellFileId;
    u32 animFileId;
    int i;

    if (flag) {
        fileId = 0x1C;
    } else {
        fileId = 0x1D;
    }
    cellFileId = sub_0207449C();
    animFileId = sub_020744A8();
    for (i = 0; i < count; i++) {
        SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_1_7_7, fileId, TRUE, _0221F194[screen], resIds[GF_GFX_RES_TYPE_CHAR] + i);
    }
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_poketool_icongra_poke_icon, cellFileId, FALSE, resIds[GF_GFX_RES_TYPE_CELL]);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_poketool_icongra_poke_icon, animFileId, FALSE, resIds[GF_GFX_RES_TYPE_ANIM]);
    if (spriteSys->paletteOffset == -1) {
        spriteSys->paletteOffset = SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_poketool_icongra_poke_icon, sub_02074490(), FALSE, 3, _0221F194[screen], resIds[GF_GFX_RES_TYPE_PLTT]);
    }
}

void ov98_0221E970(Ov98SpriteContext *spriteSys, ManagedSprite *sprite, const Ov98MonInfo *mon, BOOL isMain, BOOL animate) {
    NNSG2dCharacterData *charData;
    void *buf;
    u32 form;
    u32 species;
    u32 size;
    u8 pal;

    size = 0x200;
    if (animate) {
        size <<= 1;
    }
    species = mon->species;
    form = mon->form;
    buf = ov98_0221EAA8(spriteSys, GetMonIconNaixEx(species, FALSE, form), &charData);
    ov98_0221E9FC(sprite, charData->pRawData, size);
    Heap_Free(buf);
    ManagedSprite_SetDrawFlag(sprite, FALSE);
    pal = GetMonIconPaletteEx(species, form, FALSE);
    ManagedSprite_SetPaletteOverride(sprite, pal + spriteSys->paletteOffset);
    if (animate) {
        ManagedSprite_SetAnim(sprite, 1);
        ManagedSprite_SetAnimSpeed(sprite, FX32_ONE);
        ManagedSprite_SetAnimateFlag(sprite, TRUE);
    }
}
