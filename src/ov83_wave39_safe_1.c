#include "ov83_wave39_safe_private.h"

void ov83_02246C2C(void *p) {
    u32 i;
    PTR(p, 0x5fc) = ListMenuItems_New(3, 0x6b);
    for (i = 0; i < 3; i++) {
        ListMenuItems_AppendFromMsgData(PTR(p, 0x5fc), PTR(p, 0x20), i + 0x16, i);
    }
    ov83_022469E4(p, 3, 0x11, 8, 0xd);
}

void ov83_02246C70(void *p) {
    int n = ov80_02237B24(U8(p, 9), 1);
    ov83_0224773C((u8 *)p + 0x4e4, n, 0);
    ov83_0224773C((u8 *)p + 0x4f4, n, 0);
    ov83_02247CE8(PTR(p, 0x5f8));
    ListMenuItems_Delete(PTR(p, 0x5fc));
    U8(p, 0xf) &= ~4;
}
