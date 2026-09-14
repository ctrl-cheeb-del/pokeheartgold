#include "global.h"

#include "render_window_sprite_setup_private.h"

void sub_0200F600(FieldSpriteManager *manager, enum HeapID heapId) {
    SpriteResourceCountsListUnion counts = _020F5C60;

    FieldSpriteManager_InitEmptyResLists(manager, &counts, 1, heapId);
}

void sub_0200F62C(FieldSpriteManager *manager) {
    FieldSpriteManager_AddPlttRes(manager, (NarcId)0x26, 0x32, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 0x15CD5);
    FieldSpriteManager_AddCellRes(manager, (NarcId)0x26, 0x30, FALSE, 0x15CD5);
    FieldSpriteManager_AddAnimRes(manager, (NarcId)0x26, 0x2F, FALSE, 0x15CD5);
    FieldSpriteManager_AddCharRes(manager, (NarcId)0x26, 0x31, FALSE, NNS_G2D_VRAM_TYPE_2DMAIN, 0x15CD5);
}

void sub_0200F684(RenderWindowSpriteManager *manager, int x, int y) {
    ManagedSpriteTemplate template = _020F5C78;

    template.x = (x + 5) * 8;
    template.y = (y + 5) * 8;
    manager->sprite = FieldSpriteManager_CreateManagedSprite(&manager->manager, &template);
    SpriteList_RenderAndAnimateSprites(manager->manager.spriteList);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
}
