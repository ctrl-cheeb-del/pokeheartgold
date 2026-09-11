#include "overlay_98_remaining_internal.h"

void ov98_0221E6F0(Ov98SpriteContext *ctx, ManagedSprite **sprites, const int *resources, u32 activeCount, u32 startIndex, s16 x, s16 y, BOOL subScreen) {
    ManagedSpriteTemplate template = { 0 };
    u32 i;
    s32 xpos;
    ManagedSprite **out;

    GF_ASSERT(activeCount <= 10);
    xpos = x;
    out = sprites + startIndex;
    for (i = 0; i < 10; i++) {
        template.animation = i < activeCount;
        template.resIdList[0] = resources[0];
        template.resIdList[1] = resources[1];
        template.resIdList[2] = resources[2];
        template.resIdList[3] = resources[3];
        template.vram = subScreen ? NNS_G2D_VRAM_TYPE_2DMAIN : NNS_G2D_VRAM_TYPE_2DSUB;
        template.x = xpos;
        template.y = y;
        {
            ManagedSprite *sprite = ov98_0221E6E0(ctx, &template);
            *out++ = sprite;
            ManagedSprite_SetAnimateFlag(sprite, TRUE);
        }
        xpos += 16;
    }
}
