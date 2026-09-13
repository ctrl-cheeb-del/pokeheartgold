#include "r40_unk_02011080_private.h"

void sub_02011080(void *data, int arg1, int kind, u32 arg3, u32 arg4) {
    memset(data, 0, 0x30C);
    if (kind == 1) {
        *(u32 *)((u8 *)data + 0x180) = arg3;
        ((u8 *)data)[0x308] = kind;
        ((u8 *)data)[0x309] = arg1;
        return;
    }
    *(u32 *)((u8 *)data + 0x180) = arg3;
    *(u32 *)((u8 *)data + 0x304) = arg4;
    ((u8 *)data)[0x308] = kind;
    ((u8 *)data)[0x309] = arg1;
}
