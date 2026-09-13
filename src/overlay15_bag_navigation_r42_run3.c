#include "overlay15_bag_navigation_r42_private.h"

s32 ov15_021FA6C0(BagWorkRaw *work, s32 pocket, s32 direction) {
    s32 i;
    for (i = 0; i < 8; i++) {
        pocket += direction;
        if (pocket < 0) {
            pocket = 7;
        } else if (pocket == 8) {
            pocket = 0;
        }
        if (ov15_021FA68C(work, pocket) != -1) {
            break;
        }
    }
    return pocket;
}

void ov15_021FA6F4(BagWorkRaw *work, BagPocketEntryRaw *entry) {
    s32 count = ov15_021FA074(work);
    ov15_021FD574(work, 0, count, 0);
    ov15_021FF364(work, entry->cursor, -1, 0);
    ov15_021FF6BC(work, entry->unk_09, entry->cursor, 0);
    count = ov15_021FA074(work);
    ov15_02200140(work, entry, count, 1);
}
