#include "to46_overlay108_gap06_private.h"

int ov108_021E96FC(void *arg, u32 *didSelect) {
    int hit = TouchscreenHitbox_FindRectAtTouchNew(ov108_021EABF0);

    if (hit == -1) {
        *didSelect = 0;
        return 0;
    }
    if (hit == 7) {
        if (U8(arg, 0x430) != 0) {
            U8(arg, 0x430)
            --;
            ov108_021EA584(arg, 0, (u32 *)((u8 *)arg + 0x14), 0);
            *didSelect = 1;
        }
        return 0;
    }
    if (hit == 8) {
        if (U8(arg, 0x430) < U8(arg, 0x42E) - 1) {
            U8(arg, 0x430)
            ++;
            ov108_021EA584(arg, 1, (u32 *)((u8 *)arg + 0x14), 0);
            *didSelect = 1;
        }
        return 0;
    }
    if (hit != U8(arg, 0x431)) {
        U8(arg, 0x431) = hit;
        ov108_021EA2EC(arg, U8(arg, 0x431));
        ov108_021EA47C(arg);
    }
    *didSelect = 1;
    return ov108_021E9528(arg, U8(arg, 0x431));
}

void ov108_021E979C(void *arg) {
    vu32 *irqBase = (vu32 *)0x027E0000;
    if (U8(arg, 0x434) != 0) {
        u8 index = U8(arg, 0x431) + 6 * U8(arg, 0x430);
        if (U8(arg, 0x431) >= 6 || index >= U8(arg, 0x42D)) {
            ov108_021E8EA4((u8 *)arg + 0x338, 0x18, 0);
        } else {
            u8 *entry = (u8 *)PTR(arg, 0x334) + index * 5;
            ov108_021E8EA4((u8 *)arg + 0x338, entry[0], (int)(entry + 2));
        }
        U8(arg, 0x434) = 0;
    }
    if (PTR(arg, 0x43C) != NULL) {
        SpriteSystem_TransferOam(PTR(arg, 0x43C));
    }
    GF_RunVramTransferTasks();
    DoScheduledBgGpuUpdates(PTR(arg, 0x438));
    irqBase[0x3FF8 / sizeof(u32)] |= 1;
}
