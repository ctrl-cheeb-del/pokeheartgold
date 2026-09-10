#include "field_ui_8b1ac_internal.h"

void sub_0208C380(u8 *work) {
    int value = work[0x7C4];
    int rem = value % 3;
    int quot = value / 3;
    Sprite_SetPositionXY(*(void **)(work + 0x500), (s16)(rem * 32 + 32), (s16)(quot * 40 + 24));
}

void sub_0208C3C0(u8 *work) {
    if (Sprite_GetDrawFlag(*(void **)(work + 0x50C)) == 1) {
        Sprite_UpdateAnim(*(void **)(work + 0x50C), 0x1000);
    }
}
