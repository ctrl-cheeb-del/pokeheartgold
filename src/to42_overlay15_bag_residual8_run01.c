#include "to42_overlay15_bag_residual8_private.h"

int ov15_021FAD28(int index) {
    if (gSystem.newKeys & 0x40) {
        return ov15_02200584[index * 4] - 8;
    }
    if (gSystem.newKeys & 0x80) {
        return ov15_02200585[index * 4] - 8;
    }
    if (gSystem.newKeys & 0x20) {
        return ov15_02200586[index * 4] - 8;
    }
    if (gSystem.newKeys & 0x10) {
        return ov15_02200587[index * 4] - 8;
    }
    return index;
}
