#include "global.h"

#include "r40_overlay_103_residual_16_private.h"

void ov103_021EDF88(R40Ov103Ctx16 *ctx) {
    OamManagerParam oam;
    OamCharTransferParam transfer;
    SpriteResourceCountsListUnion counts;
    ctx->spriteSystem = SpriteSystem_Alloc((enum HeapID)0x9D);
    ctx->spriteManager = SpriteManager_New(ctx->spriteSystem);
    oam = ov103_021EED38;
    transfer = ov103_021EED0C;
    SpriteSystem_Init(ctx->spriteSystem, &oam, &transfer, 0x20);
    counts = ov103_021EED20;
    SpriteSystem_InitSprites(ctx->spriteSystem, ctx->spriteManager, 7);
    SpriteSystem_InitManagerWithCapacities(ctx->spriteSystem, ctx->spriteManager, &counts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(ctx->spriteSystem), 0, 2 << 20);
}
