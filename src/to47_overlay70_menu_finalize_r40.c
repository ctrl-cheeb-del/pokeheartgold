#include "to47_overlay70_menu_finalize_r40_private.h"

int ov70_02243B2C(void *work) {
    sub_02019688(PTR(work, 0x1c), 0, 0x64, 0x1e, 1);
    sub_02019B08(PTR(work, 0x1c), 0);
    ov70_0224190C(work, 3);
    U32(work, 0x5c) = ov70_0223F904((void **)((u8 *)work + 0x34), PTR(work, 0x2c), S16(work, 0x3e) + ov70_02245E84[S16(work, 0x3c)]);
    ov70_0224352C(work, 0, U32(work, 0x5c));
    S16(work, 0x5a) = 0;
    ov70_02243F00(PTR(work, 0x1c), PTR(work, 0x38), (u8 *)PTR(work, 4) + 0x50, S16(work, 0x5a), ov70_02242508(U32(work, 0x5c), 5));
    ov70_02243EB8(PTR(work, 0x1c), PTR(work, 0x24), (u8 *)PTR(work, 4) + 0xe0, 0x44);
    sub_020196E8(PTR(work, 0x1c), 0, 1, 0);
    U32(work, 0x48) = 0;
    {
        u32 i = U32(work, 0x48) * 2;
        ov70_02238F9C(PTR(work, 0xc), ov70_02245D8A[i], ov70_02245D8B[i]);
    }
    ov70_02238F9C(PTR(work, 0x10), 0xb0, 0x88);
    ov70_02238F9C(PTR(work, 0x14), 0x58, 0x88);
    Sprite_SetDrawFlag(PTR(work, 0xc), 1);
    Sprite_SetDrawFlag(PTR(work, 0x10), 1);
    Sprite_SetDrawFlag(PTR(work, 0x14), 1);
    U32(work, 0x4c) = 0x19;
    return -1;
}

int ov70_02243C08(void *work) {
    int result = ov70_02242C64(work);
    switch (result) {
    case -2:
        sub_020198FC(PTR(work, 0x1c), 0, 4, 0, 4);
        Sprite_SetDrawFlag(PTR(work, 0xc), 0);
        Sprite_SetDrawFlag(PTR(work, 0x10), 0);
        Sprite_SetDrawFlag(PTR(work, 0x14), 0);
        U32(work, 0x4c) = 2;
        U32(work, 0x50) = 0x1a;
        break;
    case -1:
        break;
    default:
        sub_020198FC(PTR(work, 0x1c), 0, 6, 0, 6);
        Sprite_SetDrawFlag(PTR(work, 0xc), 0);
        Sprite_SetDrawFlag(PTR(work, 0x10), 0);
        Sprite_SetDrawFlag(PTR(work, 0x14), 0);
        U32(work, 0x4c) = 3;
        U32(work, 0x50) = 0x1b;
        S16(work, 0x42) = result;
        break;
    }
    return -1;
}
