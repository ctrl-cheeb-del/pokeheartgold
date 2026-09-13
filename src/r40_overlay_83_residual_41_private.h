#ifndef POKEHEARTGOLD_OVERLAY_83_RESIDUAL_41_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY_83_RESIDUAL_41_PRIVATE_H
#include "global.h"
typedef struct Ov83SpriteHolder {
    void *unk0;
    void *sprite;
} Ov83SpriteHolder;
void *Sprite_GetMatrixPtr(void *sprite);
void Sprite_SetMatrix(void *sprite, const void *matrix);
void ov83_02247568(Ov83SpriteHolder *holder, int x, int y);
void ov83_0224759C(Ov83SpriteHolder *holder, int x, int y);
#endif
