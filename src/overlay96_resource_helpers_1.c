#include "overlay96_resource_helpers_private.h"

struct R21SpriteTemplate {
    void *spriteList;
    void *resource;
    u32 zero08;
    u32 zero0c;
    u32 zero10;
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    u16 rotation;
    u16 pad22;
    u32 affine;
    u32 priority;
    void *heap;
};

void ov96_021F8A50(u8 *obj) {
    CreateSpriteResourcesHeader(obj + 0x2d8, 0x67, 0x67, 0x67,
        0x67, -1, -1, 0, 0,
        PTR(obj,0x2a8), PTR(obj,0x2ac), PTR(obj,0x2b0), PTR(obj,0x2b4), 0, 0);
}

void ov96_021F8A98(R21SpriteTemplate *out, u8 *ctx, void *unused, u32 priority) {
    out->spriteList = PTR(ctx, 0x17c);
    out->resource = U8P(ctx, 0x2d8);
    out->zero08 = 0;
    out->zero0c = 0;
    out->zero10 = 0;
    out->scaleX = 0x1000;
    out->scaleY = 0x1000;
    out->scaleZ = 0x1000;
    out->rotation = 0;
    out->affine = 2;
    out->priority = priority;
    out->heap = PTR(ctx, 0);
}

void *ov96_021F8ACC(void *template, s32 seq, s32 priority) {
    void *sprite = Sprite_CreateAffine(template);
    Sprite_SetAnimActiveFlag(sprite, 1);
    Sprite_SetAnimCtrlSeq(sprite, seq);
    Sprite_SetDrawFlag(sprite, 0);
    Sprite_SetDrawPriority(sprite, priority);
    return sprite;
}
