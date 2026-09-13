#include "overlay102_scroll_ui_r37_private.h"

BOOL ov102_021EBEC8(u8 *p) {
    if (*(u32 *)(p + 0x80) == 0) {
        if (!ov102_021EC3AC(p + 0x40)) {
            goto fail;
        }
        ToggleBgLayer(2, 0);
        return TRUE;
    }
    return TRUE;

fail:
    return FALSE;
}

void ov102_021EBEF4(u8 *p, int enabled) {
    if (enabled != 0) {
        Sprite_SetDrawFlag(*(void **)(p + 0x30), TRUE);
        Sprite_SetDrawFlag(*(void **)(p + 0x34), ov102_021E9050(*(u8 **)(p + 4)));
        Sprite_SetDrawFlag(*(void **)(p + 0x38), ov102_021E9064(*(u8 **)(p + 4)));
    } else {
        Sprite_SetDrawFlag(*(void **)(p + 0x30), enabled);
        Sprite_SetDrawFlag(*(void **)(p + 0x34), FALSE);
        Sprite_SetDrawFlag(*(void **)(p + 0x38), FALSE);
    }
}

void ov102_021EBF38(u8 *p, u32 index) {
    VecFx32 matrix;

    if (index == -1) {
        matrix.x = 14 << 16;
        matrix.y = 11 << 16;
        matrix.z = 0;
        Sprite_SetMatrix(*(void **)(p + 0x30), &matrix);
        Sprite_SetAnimCtrlSeq(*(void **)(p + 0x30), 0x10);
    } else {
        matrix.x = ((index & 1) * 0x70 + 0x48) << 12;
        matrix.y = ((index >> 1) * 0x18 + 0x38) << 12;
        matrix.z = 0;
        Sprite_SetMatrix(*(void **)(p + 0x30), &matrix);
        Sprite_SetAnimCtrlSeq(*(void **)(p + 0x30), 8);
    }
}
