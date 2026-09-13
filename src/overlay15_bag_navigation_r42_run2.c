#include "overlay15_bag_navigation_r42_private.h"

s32 ov15_021FA578(BagWorkRaw *work, s32 direction) {
    BagContextRaw *ctx = PTR(BagContextRaw, work, 0x234);
    BagPocketEntryRaw *entry = &ctx->pockets[ctx->pocket];
    if (direction > 0) {
        s32 cursor = entry->cursor + 6;
        if (cursor < entry->unk_09) {
            entry->cursor = cursor;
        } else {
            entry->cursor = 0;
        }
    } else {
        s32 cursor = entry->cursor - 6;
        if (cursor >= 0) {
            entry->cursor = cursor;
        } else {
            entry->cursor = ((entry->unk_09 - 1) / 6) * 6;
        }
    }
    if (U8(work, 0x671) == 1) {
        ov15_021FAD80(work, entry);
        ov15_021FFF34(work, PTR(void, work, 0x66c));
        return 3;
    }
    ov15_021FA6F4(work, entry);
    ov15_021FA170(work);
    switch (U8(PTR(void, work, 0x234), 0x65)) {
    case 2:
        return 16;
    case 1:
        return 14;
    case 3:
        return 26;
    default:
        return 1;
    }
}

void ov15_021FA620(BagWorkRaw *work) {
    u8 value = U8(work, 0x614);
    U8(work, 0x617) = (90 - value * 10) / (value + 1) + 6;
    U8(work, 0x618) = U8(work, 0x617) + 4;
}

s32 ov15_021FA650(BagWorkRaw *work) {
    if (gSystem.newKeys & 0x2000) {
        s32 value = ++_02201480;
        if (value >= _02201300) {
            _02201480 = 0;
        }
        ov15_021FD574(work, 1, _02201300, _02201480);
    }
    return 0;
}
