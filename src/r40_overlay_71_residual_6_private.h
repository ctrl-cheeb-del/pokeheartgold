#ifndef POKEHEARTGOLD_OVERLAY_71_RESIDUAL_6_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY_71_RESIDUAL_6_PRIVATE_H
#include "global.h"
typedef struct Ov71SrcR6 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Ov71SrcR6;
typedef struct Ov71CtxR6 {
    void *opt;
    u32 zero4;
    void *palette;
    u32 c;
    u32 d;
    u32 zero14;
    u32 zero18;
    u32 zero1c;
    u8 kind;
} Ov71CtxR6;
typedef struct Ov71OwnerR6 {
    u8 pad[0x18];
    void *spriteList;
} Ov71OwnerR6;
typedef struct Ov71SpriteTemplateR6 {
    void *list;
    void *header;
    s32 x, y, z;
    u32 priority;
    u32 screen;
    u32 heap;
} Ov71SpriteTemplateR6;
void *Sprite_Create(const void *template);
void Sprite_SetAnimActiveFlag(void *sprite, int flag);
void Sprite_SetAnimSpeed(void *sprite, int speed);
void ov71_02247320(Ov71CtxR6 *ctx, Ov71SrcR6 *src, void *opt, void *palette, u32 kind);
void *ov71_02247340(Ov71OwnerR6 *owner, void *header, int x, int y, u32 priority, u32 screen);
#endif
