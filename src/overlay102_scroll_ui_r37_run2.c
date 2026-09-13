#include "overlay102_scroll_ui_r37_private.h"

BOOL ov102_021EC05C(u8 *p) {
    if (ov102_021EC2EC(p + 0x60)) {
        Sprite_SetDrawFlag(*(void **)(p + 0x34), ov102_021E9050(*(u8 **)(p + 4)));
        Sprite_SetDrawFlag(*(void **)(p + 0x38), ov102_021E9064(*(u8 **)(p + 4)));
        return TRUE;
    } else {
        return FALSE;
    }
}

void ov102_021EC090(u8 *p, int amount) {
    int start;
    int end;

    if (amount > 0) {
        start = (u8)(*(int *)(p + 0x8c) + 0x78);
        end = (u8)(start + amount * 0x18);
    } else {
        end = *(int *)(p + 0x8c);
        start = (u8)(end + amount * 0x18);
    }
    if (start < end) {
        FillWindowPixelRect(p + 0x10, 0, 0, start, 0xd0, end - start);
    } else {
        FillWindowPixelRect(p + 0x10, 0, 0, start, 0xd0, 0x100 - start);
        FillWindowPixelRect(p + 0x10, 0, 0, 0, 0xd0, end);
    }
}
