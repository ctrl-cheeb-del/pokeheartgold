#include "global.h"

#include "r40_overlay_103_residual_17_private.h"

void ov103_021EE078(R40Ctx17 *ctx, u32 index) {
    if (ctx->sprites[index] != NULL) {
        Sprite_DeleteAndFreeResources(ctx->sprites[index]);
        ctx->sprites[index] = NULL;
    }
}
