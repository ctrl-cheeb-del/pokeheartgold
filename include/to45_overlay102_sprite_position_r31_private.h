#ifndef TO45_OVERLAY102_SPRITE_POSITION_R31_PRIVATE_H
#define TO45_OVERLAY102_SPRITE_POSITION_R31_PRIVATE_H

#include "global.h"

void ov102_021EA270(void *work, void *resource, int index, int value);
void *ov102_021EA2B4(void *work, void *resource, int x, int y, int anim, int kind);
u8 ov102_021E8F7C(void *args);
void ov102_021EC4CC(u32 word, u32 *column, u32 *row);
void Sprite_SetAnimCtrlSeq(void *sprite, int sequence);
void Sprite_SetDrawFlag(void *sprite, int draw);
void Sprite_SetMatrix(void *sprite, const VecFx32 *position);

typedef struct Ov102SpriteWork31 {
    void *owner;
    void *args;
    u8 padding[0x54];
    void *sprite;
} Ov102SpriteWork31;

void ov102_021EB950(u8 *work);
void ov102_021EB98C(u8 *work, int draw);
void ov102_021EB9C0(Ov102SpriteWork31 *work, u32 index);

#endif
