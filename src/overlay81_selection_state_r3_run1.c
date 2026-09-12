#include "overlay81_selection_state_r3_private.h"

void ov81_0223F320(u8 *work) {
    void *object;

    ov80_02236DD4(work[9]);
    object = *(void **)(work + 0x360 + *(u32 *)(work + 0x468) * 4);
    ov81_02242F54(object);
    object = *(void **)(work + 0x360 + *(u32 *)(work + 0x468) * 4);
    ov81_02242FB0(object, 1);
    object = *(void **)(work + 0x360 + *(u32 *)(work + 0x468) * 4);
    ov81_02242F94(object, 0);
    ov81_022408A0(work, 0, work[0x11] + 1);
    work[0x10] = ov81_0224086C(work, 0);
    ov81_02241FEC(work);
    ov81_0224218C(work);
}
