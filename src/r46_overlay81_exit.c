#include "r46_overlay81_exit_private.h"

BOOL ov81_0223E234(void *man, u32 *state) {
    u8 *p = OverlayManager_GetData(man);
    u8 *q;
    int k;
    int i;

#pragma unused(state)
    if (PaletteData_GetSelectedBuffersBitmask(PTR(p, 0x1A0)) != 0) {
        PaletteData_ScheduleFadeTaskEndIfNoSelectedBuffers(PTR(p, 0x1A0));
        U32(p, 0x478) = 0xFF;
        return FALSE;
    }
    if (ov81_02240F08(p, 0) == 1) {
        i = 0;
        if (i < ov81_02240F18(p[9])) {
            q = p;
            k = 0;
            do {
                *(u16 *)((u8 *)PTR(p, 0x3D4) + k) = U16(q, 0x3C8);
                q += 2;
                k += 2;
                i++;
            } while (i < ov81_02240F18(p[9]));
        }
    } else {
        u8 *src;
        int byteOffset;
        int count;

        count = 0;
        src = p;
        byteOffset = count;
        do {
            *(u16 *)((u8 *)PTR(p, 0x3D4) + byteOffset) = U16(src, 0x3C8);
            src += 2;
            byteOffset += 2;
            count++;
        } while (count < 2);
        if (BIT(p[0x13], 3) == 0) {
            *(u16 *)PTR(p, 0x3D4) = 0xFF;
            *(u16 *)((u8 *)PTR(p, 0x3D4) + 2) = 0xFF;
        }
    }
    TextFlags_SetCanTouchSpeedUpPrint(0);
    ov81_02241BC8(PTR(p, 0x46C));
    ov81_02243220(PTR(p, 0x464));
    ov81_02240BB0(p);
    OverlayManager_FreeData(man);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(0x64);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_80));
    return TRUE;
}
