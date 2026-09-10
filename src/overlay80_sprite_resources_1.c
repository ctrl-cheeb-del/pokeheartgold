#include "overlay80_sprite_resources_internal.h"

void ov80_02239AF8(void *narc, void *system, void *manager, void *paletteData, u16 index) {
    const Overlay80SpriteResource *resource;
    if (index >= 4) {
        GF_AssertFail();
    }
    resource = &ov80_0223DA54[index];
    SpriteSystem_LoadCharResObjFromOpenNarc(narc, system, manager, resource->charId, 1, 1, resource->charId);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(paletteData, 2, narc, system, manager, resource->paletteId, 0, 1, 1, resource->paletteId);
    SpriteSystem_LoadCellResObjFromOpenNarc(narc, system, manager, resource->cellId, 1, resource->cellId);
    SpriteSystem_LoadAnimResObjFromOpenNarc(narc, system, manager, resource->animId, 1, resource->animId);
}

void ov80_02239B7C(void *manager, u32 index) {
    const Overlay80SpriteResource *resource;
    if (index >= 4) {
        GF_AssertFail();
    }
    resource = &ov80_0223DA54[index];
    SpriteManager_UnloadCharObjById(manager, resource->charId);
    SpriteManager_UnloadPlttObjById(manager, resource->paletteId);
    SpriteManager_UnloadCellObjById(manager, resource->cellId);
    SpriteManager_UnloadAnimObjById(manager, resource->animId);
}

void *ov80_02239BB8(void *system, void *manager, u32 index) {
    void *sprite;
    if (index >= 4) {
        GF_AssertFail();
    }
    sprite = SpriteSystem_NewSprite(system, manager, &ov80_0223DA54[index]);
    Sprite_TickFrame(*(void **)sprite);
    return sprite;
}

void ov80_02239BE8(void *sprite) {
    Sprite_DeleteAndFreeResources(sprite);
}
