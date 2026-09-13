#include "overlay15_bag_navigation_r42_private.h"

s32 ov15_021FA12C(BagWorkRaw *work) {
    BagContextRaw *ctx = PTR(BagContextRaw, work, 0x234);
    BagPocketEntryRaw *entry = &ctx->pockets[ctx->pocket];
    u32 index = entry->cursor + S32(work, 0x644) - 8;
    if (ov15_022008B0[ctx->pocket] <= index) {
        return 0;
    }
    return ((u16 *)entry->items)[index * 2];
}

void ov15_021FA170(BagWorkRaw *work) {
    s32 value = S32(work, 0x644);
    if (value >= 8 && value <= 13) {
        u32 item = ov15_021FA12C(work);
        if (item != 0) {
            ov15_021FECA0(work, work->raw + 4, item);
        } else {
            ov15_021FECC4(work, work->raw + 4);
        }
    } else if (value >= 0 && value <= 7) {
        ov15_021FECD8(work, work->raw + 4, value);
    } else {
        ov15_021FECC4(work, work->raw + 4);
    }
}
