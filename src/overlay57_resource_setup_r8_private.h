#ifndef TO45_OVERLAY57_RESIDUAL8_PRIVATE_H
#define TO45_OVERLAY57_RESIDUAL8_PRIVATE_H

#include "global.h"

#include "gf_gfx_loader.h"
#include "palette.h"
#include "sprite_system.h"

typedef struct Ov57R8Work {
    u8 pad00[0xDC];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    NARC *narc;
    PaletteData *paletteData;
    u8 padEC[0x328];
    ManagedSprite *sprites[13];
} Ov57R8Work;

void ov57_022385A4(void *, ManagedSprite *, s32, s32);
extern const s16 ov57_0223BE48[13][2];
extern const s16 ov57_0223BE7C[13][2];

void ov57_02239BEC(Ov57R8Work *, NARC *);
void ov57_02239C88(Ov57R8Work *, NARC *);
void ov57_02239CE8(Ov57R8Work *, NARC *);
void ov57_02239D48(Ov57R8Work *, NARC *);
void ov57_02239EB4(Ov57R8Work *);

#endif
