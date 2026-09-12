#include "overlay14_input_dispatch_r22_private.h"

u32 ov14_021EB290(void *work)
{
    ov14_021F7D50[U8_AT(work, 0x1e)].init(work);
    return 10;
}

u32 ov14_021EB2A8(void *work)
{
    if (!OverlayManager_Run(PTR_AT(work, 0x14))) {
        return 10;
    }
    OverlayManager_Delete(PTR_AT(work, 0x14));
    ov14_021F7D50[U8_AT(work, 0x1e)].exit(work);
    U32_AT(work, 0x30) = ov14_021F7D50[U8_AT(work, 0x1e)].next;
    return 0;
}

void ov14_021EB2EC(void *work)
{
    u32 msg;

    PlaySE(0x60c);
    switch (U32_AT(PTR_AT(work, 0), 8)) {
    case 0:
        ov14_021F0BF4(work);
        ov14_021F685C(work, 0, 0, 0x27);
        ov14_021F43F4(PTR_AT(work, 0x34), 0);
        ov14_021F3488(work, 1, 1);
        ov14_021E7588(work, 0x1e);
        msg = 0x5b;
        break;
    case 1:
        ov14_021F685C(work, 0, 0, 0x27);
        ov14_021E7588(work, 0);
        msg = 0x51;
        break;
    case 2:
        ov14_021E7588(work, 0);
        msg = 0xc;
        break;
    case 3:
        ov14_021F3488(work, 0x81, 1);
        ov14_021E7588(work, 0);
        msg = 0x75;
        break;
    }
    ov14_021F01D8(work, msg);
}
