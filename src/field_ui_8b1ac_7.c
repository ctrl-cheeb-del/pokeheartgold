#include "field_ui_8b1ac_internal.h"

void sub_0208BC78(u8 *work) {
    s16 pos[2];
    Sprite_GetPositionXY(*(void **)(work + 0x428), &pos[1], &pos[0]);
    Sprite_SetPositionXY(*(void **)(work + 0x42C), pos[1], pos[0]);
    Sprite_SetDrawFlag(*(void **)(work + 0x42C), 1);
}

void sub_0208BCB4(u8 *work) {
    Sprite_SetPositionXY(*(void **)(work + 0x42C), 0x44, 0xA8);
    Sprite_SetAnimCtrlSeq(*(void **)(work + 0x42C), 0);
}
