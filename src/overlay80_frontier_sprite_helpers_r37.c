#include "overlay80_frontier_sprite_helpers_r37_private.h"

void ov80_0222F1D0(Ov80R37FrontierMap *map, u32 resourceId) {
    u32 index = resourceId - 50000;
    Sprite_DeleteAndFreeResources(map->sprites[index]);
    map->sprites[index] = NULL;
    SpriteManager_UnloadCharObjById(map->spriteManager, resourceId);
    SpriteManager_UnloadPlttObjById(map->spriteManager, resourceId);
    SpriteManager_UnloadCellObjById(map->spriteManager, resourceId);
    SpriteManager_UnloadAnimObjById(map->spriteManager, resourceId);
}

void ov80_0222F210(Ov80R37FrontierMap *map) {
    SpriteSystem_LoadPaletteBuffer(map->plttData, PLTTBUF_MAIN_OBJ, map->spriteSystem, map->spriteManager, NARC_poketool_icongra_poke_icon, sub_02074490(), FALSE, 3, NNS_G2D_VRAM_TYPE_2DMAIN, 2000);
    SpriteSystem_LoadCellResObj(map->spriteSystem, map->spriteManager, NARC_poketool_icongra_poke_icon, sub_02074498(), FALSE, 2000);
    SpriteSystem_LoadAnimResObj(map->spriteSystem, map->spriteManager, NARC_poketool_icongra_poke_icon, sub_020744A4(), FALSE, 2000);
}

void ov80_0222F278(Ov80R37FrontierMap *map) {
    SpriteManager_UnloadCellObjById(map->spriteManager, 2000);
    SpriteManager_UnloadAnimObjById(map->spriteManager, 2000);
    SpriteManager_UnloadPlttObjById(map->spriteManager, 2000);
}

Ov80R37ManagedSprite *ov80_0222F29C(Ov80R37FrontierMap *map, void *mon, s32 index, s32 x, s32 y) {
    Ov80R37ManagedSpriteTemplate template;
    Ov80R37ManagedSprite *sprite;
    GF_ASSERT(index < 8);
    SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType(map->spriteSystem, map->spriteManager, NARC_poketool_icongra_poke_icon, Pokemon_GetIconNaix(mon), FALSE, NNS_G2D_VRAM_TYPE_2DMAIN, index + 2000);
    template = ov80_0223BD80;
    template.resIdList[GF_GFX_RES_TYPE_CHAR] += index;
    template.x = x;
    template.y = y;
    template.drawPriority = 200;
    sprite = SpriteSystem_NewSprite(map->spriteSystem, map->spriteManager, &template);
    Sprite_SetPalOffsetRespectVramOffset(sprite->sprite, Pokemon_GetIconPalette(mon));
    ManagedSprite_TickFrame(sprite);
    return sprite;
}
