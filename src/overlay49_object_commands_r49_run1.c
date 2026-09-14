#include "overlay49_object_commands_r49_private.h"

u32 ov49_0225E85C(void *p, u32 i, u32 flag, u32 arg) {
    u8 *base;
    u32 off;

    if (i < U8_AT(p, 0x608)) {
        base = (u8 *)p + 0x248;
        off = i * 12;
        if (flag) {
            ov49_0225EB54(base + off, PTR_AT(p, 4), arg);
        } else {
            ov49_0225EB84(base + off);
        }
        return 1;
    }
    return 0;
}

void ov49_0225E894(void *p, u32 v) {
    s32 i;

    for (i = 0; i < U8_AT(p, 0x609); i++) {
        ov49_0225ECD4(&((Ov49Slot12 *)((u8 *)p + 0x368))[i], v);
    }
}
