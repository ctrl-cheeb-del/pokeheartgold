#include "overlay81_selection_state_r3_private.h"

void ov81_0223F684(u8 *work) {
    *(u16 *)(work + 0x3C8 + work[0x11] * 2) = *(u32 *)(work + 0x468);
    work[0x11]++;
    work[0x13] |= 4;
}
