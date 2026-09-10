#include "overlay_98_helpers_internal.h"

void *ov98_0221E5C0(Ov98SpriteContext *ctx) {
    GF_ASSERT(ctx != NULL);
    return ctx->spriteSystem;
}

void *ov98_0221E5D0(Ov98SpriteContext *ctx) {
    GF_ASSERT(ctx != NULL);
    return ctx->spriteManager;
}

Ov98SpriteContext *ov98_0221E5E0(enum HeapID heapId, SpriteResourceCountsListUnion *counts, int maxSprites) {
    Ov98SpriteContext *ctx = Heap_Alloc(heapId, sizeof(Ov98SpriteContext));
    OamManagerParam oam;
    OamCharTransferParam transfer;

    ctx->heapId = heapId;
    ctx->spriteSystem = SpriteSystem_Alloc(heapId);
    ctx->spriteManager = SpriteManager_New(ctx->spriteSystem);
    ctx->narc = NARC_New((NarcId)20, ctx->heapId);
    ctx->paletteOffset = -1;
    oam = ov98_0221F1C0;
    transfer = ov98_0221F1AC;
    transfer.maxTasks = maxSprites;
    SpriteSystem_Init(ctx->spriteSystem, &oam, &transfer, 32);
    SpriteSystem_InitSprites(ctx->spriteSystem, ctx->spriteManager, maxSprites);
    SpriteSystem_InitManagerWithCapacities(ctx->spriteSystem, ctx->spriteManager, counts);
    ctx->paletteData = PaletteData_Init(ctx->heapId);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    return ctx;
}

void ov98_0221E684(Ov98SpriteContext *ctx, ManagedSprite **sprites, u32 count) {
    u32 i;
    NARC_Delete(ctx->narc);
    PaletteData_Free(ctx->paletteData);
    for (i = 0; i < count; i++) {
        if (sprites[i] != NULL) {
            Sprite_DeleteAndFreeResources(sprites[i]);
            sprites[i] = NULL;
        }
    }
    SpriteSystem_FreeResourcesAndManager(ctx->spriteSystem, ctx->spriteManager);
    SpriteSystem_Free(ctx->spriteSystem);
    Heap_Free(ctx);
}

void ov98_0221E6CC(Ov98SpriteContext *ctx) {
    GF_ASSERT(ctx != NULL);
    SpriteSystem_DrawSprites(ctx->spriteManager);
}

ManagedSprite *ov98_0221E6E0(Ov98SpriteContext *ctx, const ManagedSpriteTemplate *template) {
    return SpriteSystem_NewSprite(ctx->spriteSystem, ctx->spriteManager, template);
}
