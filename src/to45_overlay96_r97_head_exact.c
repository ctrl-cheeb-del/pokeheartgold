#include "to45_overlay96_r97_head_private.h"

void ov96_0220C9F4(R97ItemR11 *item, u32 index, void *context) {
    MI_CpuFill8(item, 0, sizeof(*item));
    item->w[0] = (u32)context;
    item->timer.raw = (item->timer.raw & 0x3fffffff) | (index << 30);
    item->w[4] = 100;
    ov96_0220D200(&item->w[1], index, context);
}

u32 ov96_0220CA28(R97ItemR11 *item) {
    u32 result = 0;
    u32 state;

    if (item == NULL) {
        GF_AssertFail();
    }
    state = item->state.bits.state;
    switch (state) {
    case 0:
        result = ov96_0220CAC4(item);
        break;
    case 1:
        result = ov96_0220CBC0(item);
        break;
    case 2:
        result = ov96_0220CC18(item);
        break;
    case 3:
        result = ov96_0220CBEC(item);
        break;
    default:
        GF_AssertFail();
        break;
    }
    if (item->state.bits.state != 3) {
        ov96_0220D07C(item);
    }
    ov96_0220D2AC(&item->w[1], item->timer.bits.counter, item->state.bits.kind);
    item->timer.bits.counter++;
    return result;
}

u32 ov96_0220CAC4(R97ItemR11 *item) {
    u32 result = 0;

    item->state.bits.count++;
    if (item->state.bits.count >= item->timer.bits.duration) {
        if (ov96_0220CD00(item) != 0) {
            ov96_0220D0F8(item);
            ov96_021E8228((void *)item->w[0], item->timer.bits.kind, item->state.bits.kind, 7, 1);
            ov96_0220CD84(item, 1);
        } else {
            if (ov96_0220CCBC(item) != 0) {
                result += 2;
            }
            if (item->flags.bits.active != 0) {
                if (item->flags.bits.count >= 2 && ov96_0220CC38(item) != 0) {
                    ov96_0220CE04(item, result & 2);
                }
            } else {
                ov96_0220CE04(item, result & 2);
            }
        }
        item->state.bits.count = 0;
        item->timer.bits.duration = MTRandom() % 3 + 4;
    }
    if (item->flags.bits.active != 0) {
        item->flags.bits.count++;
        if (item->flags.bits.count >= 10) {
            item->flags.bits.count = 0;
            item->flags.bits.active = 0;
        }
    }
    return result;
}
