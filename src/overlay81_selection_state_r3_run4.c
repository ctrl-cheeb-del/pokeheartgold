#include "overlay81_selection_state_r3_private.h"

void ov81_0223FB64(u8 *work) {
    work[0x13] |= 8;
    *(u16 *)(work + 0x3C8 + work[0x11] * 2) = *(u32 *)(work + 0x468);
    work[0x11]++;
}

void ov81_0223FB88(u8 *work) {
    u32 frame = Options_GetFrame(*(void **)(work + 0x1B8));
    ov81_02243028(work + 0xC0, frame);
    work[0x10] = ov81_0224086C(work, 0xD);
}
