#include "overlay_98_helpers_internal.h"

void *ov98_0221EAA8(Ov98SpriteContext *ctx, int member, NNSG2dCharacterData **out) {
    return GfGfxLoader_GetCharDataFromOpenNarc(ctx->narc, member, FALSE, out, ctx->heapId);
}
