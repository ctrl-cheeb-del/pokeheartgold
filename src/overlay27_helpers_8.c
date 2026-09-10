#include "overlay_27_helpers_internal.h"

void ov27_0225B4AC(Sprite **sprites, s32 a1) {
    s32 i;
    for (i = 0; i < 9; i++) {
        if (sprites[i] != NULL) {
            if (a1 != i) {
                Sprite_SetOamMode(sprites[i], 1);
            } else {
                Sprite_SetOamMode(sprites[i], 0);
            }
        }
    }
}
