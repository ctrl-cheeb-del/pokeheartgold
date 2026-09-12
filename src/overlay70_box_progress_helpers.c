#include "overlay70_box_progress_helpers_private.h"

void ov70_02238F24(u8 *work) {
    u16 box = *(u16 *)(work + 0x11FA);
    if (box != 0) {
        PCStorage *storage = *(PCStorage **)(*(u8 **)work + 0xC);
        *(u16 *)(work + 0x11F8) += PCStorage_CountMonsAndEggsInBox(storage, box - 1);
        *(u16 *)(work + 0x11FA) += 1;
        if (*(u16 *)(work + 0x11FA) == 19) {
            *(u16 *)(work + 0x11FA) = 0;
        }
    }
}

void ov70_02238F64(u8 *work) {
    *(WaitingIcon **)(work + 0x11BC) = WaitingIcon_New((Window *)(work + 0xF18), 1);
}

void ov70_02238F80(u8 *work) {
    WaitingIcon *icon = *(WaitingIcon **)(work + 0x11BC);
    if (icon != NULL) {
        sub_0200F450(icon);
        *(WaitingIcon **)(work + 0x11BC) = NULL;
    }
}

void ov70_02238F9C(Sprite *sprite, int x, int y) {
    VecFx32 vec;
    vec.x = x << FX32_SHIFT;
    vec.y = y << FX32_SHIFT;
    Sprite_SetMatrix(sprite, &vec);
}

void ov70_02238FB4(int sub) {
    if (sub != 0) {
        G2x_SetBlendBrightness_((vu16 *)0x04000050, 30, -7);
    } else {
        G2x_SetBlendBrightness_((vu16 *)0x04001050, 30, -7);
    }
}
