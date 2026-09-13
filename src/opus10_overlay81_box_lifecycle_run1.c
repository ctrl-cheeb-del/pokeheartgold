#include "opus10_overlay81_box_lifecycle_private.h"

BOOL ov81_0223DEA8(void *man, u32 *state);
BOOL ov81_0223E234(void *man, u32 *state);
BOOL ov81_0223E318(u8 *p);
BOOL ov81_0223E520(u8 *p);
void ov81_0223E5B4(u8 *p);
void ov81_0223E87C(u8 *p);

BOOL ov81_0223DD60(void *man, u32 *state) {
    u8 *p;
    void *args;

    HandleLoadOverlay(FS_OVERLAY_ID(OVY_80), 2);
    ov81_02240D2C();
    Heap_Create(3, 0x64, 3 << 16);
    p = OverlayManager_CreateAndGetData(man, 0x48C, 0x64);
    memset(p, 0, 0x48C);
    PTR(p, 0x1A4) = GF_3DVramMan_Create(0x64, 0, 2, 0, 2, ov81_02242BC8);
    PTR(p, 0x4C) = BgConfig_Alloc(0x64);
    PTR(p, 0) = man;
    args = OverlayManager_GetArgs(man);
    U32(p, 0x1BC) = U32(args, 0);
    p[9] = U8(args, 4);
    p[0xA] = U8(args, 5);
    p[0xB] = U8(args, 6);
    U32(p, 0x3C0) = U32(args, 8);
    U32(p, 0x3C4) = U32(args, 0xC);
    PTR(p, 0x3D4) = (u8 *)args + 0x10;
    PTR(p, 0x1B8) = Save_PlayerData_GetOptionsAddr(PTR(p, 0x1BC));
    U32(p, 0x14) = 8;
    if (ov81_02240F08(p, 0) == 1) {
        p[0x12] = 6;
        PTR(p, 0x464) = ov81_02243240(p, 0);
    } else if (ov80_02237254(p[9]) == 1) {
        p[0x12] = 2;
        p[0x1A] = 3;
        p[0x1B] = 6;
        PTR(p, 0x464) = ov81_022432DC(p, 0);
    } else {
        p[0x12] = 3;
        p[0x1A] = 4;
        p[0x1B] = 5;
        PTR(p, 0x464) = ov81_022432AC(p, 0);
    }
    if (ov80_02237254(p[9]) == 1) {
        U32(p, 0x47C) = 2;
    } else {
        U32(p, 0x47C) = 3;
    }
    ov81_02241BB8((void **)(p + 0x46C));
    ov81_02240D64(p);
    TextFlags_SetCanTouchSpeedUpPrint(1);
    if (ov80_02237254(p[9]) == 1) {
        sub_02096910(p);
    }
    *state = 0;
    return TRUE;
}
