#include "overlay96_r97_item_update_private.h"

void ov96_0220D014(R97Item *item, int add, u32 unused) {
    if (((item->flags << 22) >> 31) != 0) {
        GF_AssertFail();
    }
    if (add) {
        item->state.bits.count += 30;
    }
    if (item->state.bits.count > 100) {
        item->state.bits.count = 100;
    }
    if (item->state.bits.count >= 100) {
        item->flags |= 0x200;
        item->timer.raw &= 0xFFC007FF;
    }
}

void ov96_0220D07C(R97Item *item) {
    if ((item->flags << 22) >> 31) {
        item->timer.bits.counter++;
        if (item->timer.bits.counter >= 90) {
            ov96_0220D0F8(item);
        }
    } else if (item->state.bits.count != 0) {
        item->timer.bits.counter++;
        if (item->timer.bits.counter >= 2) {
            item->timer.bits.counter = 0;
            item->state.bits.count--;
        }
    }
}
