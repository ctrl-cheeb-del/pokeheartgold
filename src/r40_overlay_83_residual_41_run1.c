#include "r40_overlay_83_residual_41_private.h"

void ov83_02247568(Ov83SpriteHolder *holder, int x, int y) {
    VecFx32 matrix = *(VecFx32 *)Sprite_GetMatrixPtr(holder->sprite);
    matrix.x = x << 12;
    matrix.y = y << 12;
    Sprite_SetMatrix(holder->sprite, &matrix);
}

void ov83_0224759C(Ov83SpriteHolder *holder, int x, int y) {
    VecFx32 matrix = *(VecFx32 *)Sprite_GetMatrixPtr(holder->sprite);
    matrix.x = x << 12;
    matrix.y = (y << 12) + 0xC0000;
    Sprite_SetMatrix(holder->sprite, &matrix);
}
