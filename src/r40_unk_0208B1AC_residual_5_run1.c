#include "r40_unk_0208B1AC_residual_5_candidate_private.h"

void sub_0208B780(u8 *work, int baseIndex, int first, int second, int value, int sign, int extraIndex) {
    u8 states[5];
    int i;
    u8 *state;
    void **sprite;
    int result;

    result = sub_0208B85C(states, first, second, value, sign);
    i = 0;
    state = states;
    sprite = (void **)work + baseIndex;
    while (i < 5) {
        if (*state == 0) {
            Sprite_SetDrawFlag(*sprite, 0);
        } else if (*state == 1) {
            Sprite_SetDrawFlag(*sprite, 1);
            Sprite_SetAnimCtrlSeq(*sprite, 3);
        } else if (*state == 2) {
            Sprite_SetDrawFlag(*sprite, 1);
            Sprite_SetAnimCtrlSeq(*sprite, 0);
        } else if (*state == 3) {
            Sprite_SetDrawFlag(*sprite, 1);
            Sprite_SetAnimCtrlSeq(*sprite, 1);
        } else if (*state == 4) {
            Sprite_SetDrawFlag(*sprite, 1);
            Sprite_SetAnimCtrlSeq(*sprite, 2);
        }
        i++;
        state++;
        sprite++;
    }
    if (result == 0) {
        Sprite_SetDrawFlag(((void **)work)[extraIndex], 0);
    } else if (result > 0) {
        Sprite_SetDrawFlag(((void **)work)[extraIndex], 1);
        Sprite_SetAnimCtrlSeq(((void **)work)[extraIndex], 4);
    } else if (result < 0) {
        Sprite_SetDrawFlag(((void **)work)[extraIndex], 1);
        Sprite_SetAnimCtrlSeq(((void **)work)[extraIndex], 5);
    }
}
