#include "r40_overlay_109_residual_10_private.h"

void ov109_021E6DE4(PhotoAlbumApp *app) {
    GF_CreateVramTransferManager(0x20, app->heapId);
    app->spriteSystem = SpriteSystem_Alloc(app->heapId);
    SpriteSystem_Init(app->spriteSystem, &ov109_021E79D0, &ov109_021E78C8, 3);
    thunk_ClearMainOAM(app->heapId);
    thunk_ClearSubOAM(app->heapId);
    app->spriteManager = SpriteManager_New(app->spriteSystem);
    SpriteSystem_InitSprites(app->spriteSystem, app->spriteManager, 5);
    sub_0200D2A4(app->spriteSystem, app->spriteManager, &ov109_021E78A8, 2, 1);
}
