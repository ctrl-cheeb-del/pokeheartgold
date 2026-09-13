#include "r40_overlay_70_residual_15_private.h"

void ov70_0223A1E4(u8 *ctx) {
    int i;
    *(void **)(ctx + 0xbbc) = String_New(0xb4, 0x3d);
    *(void **)(ctx + 0xbc0) = NewString_ReadMsgData(*(void **)(ctx + 0xba0), 0x27);
    for (i = 0; i < 10; i++, ctx += 4) {
        *(void **)(ctx + 0xbc4) = String_New(0x14, 0x3d);
    }
}
