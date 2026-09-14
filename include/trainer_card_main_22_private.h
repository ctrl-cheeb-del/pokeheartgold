#ifndef POKEHEARTGOLD_TRAINER_CARD_MAIN_22_PRIVATE_H
#define POKEHEARTGOLD_TRAINER_CARD_MAIN_22_PRIVATE_H

#include "global.h"

#include "heap.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "unk_0200A090.h"
#include "unk_0200B150.h"

typedef struct TrainerCardMainState22 {
    SpriteList *spriteList;
    G2dRenderer renderer;
    GF_2DGfxResMan *resourceManagers[2][4];
    SpriteResource *resourceObjects[2][4];
    Sprite *sprites[16];
    u8 padding_1AC[0x44];
    Sprite *specialSprites[2];
    void *rawPalettes[16];
    NNSG2dPaletteData *palettes[16];
} TrainerCardMainState22;

typedef struct TrainerCardSpritePosition22 {
    s32 x;
    s32 y;
} TrainerCardSpritePosition22;

extern const TrainerCardSpritePosition22 ov51_021E801C[16];

void ov51_021E7AF4(TrainerCardMainState22 *work, const u8 *drawFlags, int mode);
void ov51_021E7CA4(TrainerCardMainState22 *work);

#endif
