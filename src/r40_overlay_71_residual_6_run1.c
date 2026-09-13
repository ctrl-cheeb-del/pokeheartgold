#include "r40_overlay_71_residual_6_private.h"

void ov71_02247320(Ov71CtxR6 *ctx, Ov71SrcR6 *src, void *opt, void *palette, u32 kind) {
    ctx->opt = opt;
    ctx->palette = palette;
    ctx->c = src->c;
    ctx->d = src->d;
    ctx->kind = kind;
    ctx->zero4 = 0;
    ctx->zero14 = 0;
    ctx->zero18 = 0;
    ctx->zero1c = 0;
}

void *ov71_02247340(Ov71OwnerR6 *owner, void *header, int x, int y, u32 priority, u32 screen) {
    Ov71SpriteTemplateR6 template;
    void *sprite;
    template.list = owner->spriteList;
    template.header = header;
    template.x = x << 12;
    template.y = y << 12;
    template.z = 0;
    template.priority = priority;
    template.screen = screen;
    template.heap = 0x38;
    sprite = Sprite_Create(&template);
    if (sprite != NULL) {
        Sprite_SetAnimActiveFlag(sprite, 1);
        Sprite_SetAnimSpeed(sprite, 0x1000);
    }
    return sprite;
}
