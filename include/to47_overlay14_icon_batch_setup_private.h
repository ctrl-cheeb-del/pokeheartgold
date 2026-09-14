#ifndef POKEHEARTGOLD_TO47_OVERLAY14_ICON_BATCH_SETUP_PRIVATE_H
#define POKEHEARTGOLD_TO47_OVERLAY14_ICON_BATCH_SETUP_PRIVATE_H

#include "global.h"

#include "sprite_system.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))

typedef struct BoxSpriteWork {
    u8 filler_000[0x2F4];
    SpriteSystem *spriteSystem;   // 0x2F4
    SpriteManager *spriteManager; // 0x2F8
    ManagedSprite *sprites[64];   // 0x2FC
} BoxSpriteWork;

extern const ManagedSpriteTemplate ov14_021F810C;

u32 sub_02074490(void);
u32 sub_0207449C(void);
u32 sub_020744A8(void);

void ov14_021F2C84(BoxSpriteWork *work);
void ov14_021F2D1C(BoxSpriteWork *work);

#endif // POKEHEARTGOLD_TO47_OVERLAY14_ICON_BATCH_SETUP_PRIVATE_H
