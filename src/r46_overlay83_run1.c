#include "r46_overlay83_private.h"

BOOL ov83_0223DD60(OverlayManager *manager, int *state) {
    u8 *work;
    u8 *args;
    int i;

#pragma unused(state)
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_80), OVY_LOAD_ASYNC);
    ov83_0223F1C8();
    Heap_Create(HEAP_ID_3, HEAP_ID_107, 3 << 16);
    work = OverlayManager_CreateAndGetData(manager, 0x86C, HEAP_ID_107);
    memset(work, 0, 0x86C);
    PTR(work, 0x4C) = BgConfig_Alloc(HEAP_ID_107);
    PTR(work, 0) = manager;
    args = OverlayManager_GetArgs(manager);
    PTR(work, 0x50C) = PTR(args, 0);
    PTR(work, 0x510) = sub_02030CC8(PTR(work, 0x50C));
    U32_AT(work, 0x514) = sub_02030E08(PTR(work, 0x50C));
    U8_AT(work, 9) = U8_AT(args, 4);
    PTR(work, 0x7A0) = args + 0x20;
    PTR(work, 0x508) = Save_PlayerData_GetOptionsAddr(PTR(work, 0x50C));
    PTR(work, 0x7A4) = PTR(args, 0x18);
    U8_AT(work, 0x12) = 0xFF;
    U16_AT(work, 0x802) = U16_AT(args, 0x28);
    PTR(work, 4) = Save_Frontier_GetStatic(PTR(work, 0x50C));
    for (i = 0; i < 3; i++) {
        ((To46Ov83Work *)(work + i))->flags[0] = 1;
    }
    if (ov80_02237D8C(U8_AT(work, 9)) == 0) {
        U8_AT(work, 0x14) = 3;
    } else {
        U8_AT(work, 0x14) = 4;
    }
    U8_AT(work, 0x15) = 4;
    U8_AT(work, 0xC) = U8_AT(work, 0x15) - 1;
    ov83_022477E4((u32 *)(work + 0x868));
    ov83_0223F200(work);
    if (ov80_02237D8C(U8_AT(work, 9)) == 1) {
        sub_02096910(work);
    }
    return TRUE;
}
