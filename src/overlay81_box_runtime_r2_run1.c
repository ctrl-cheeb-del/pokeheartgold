#include "overlay81_box_runtime_r2_private.h"

void ov81_0223EC44(u8 *p) {
    u32 i;
    u8 *q;
    ov81_02241DDC(p, 1);
    i = 0;
    if (i < U32(p, 0x47C)) {
        q = p;
        do {
            ov81_02241E68(p, i, i, 1);
            Pokepic_SetAttr(PTR(q, 0x1AC), 6, 1);
            i++;
            q += 4;
        } while (i < U32(p, 0x47C));
    }
}

BOOL ov81_0223EC88(u8 *p) {
    if (p[8] == 0 && OverlayManager_Run(PTR(p, 4)) == 1) {
        u8 value = *(u8 *)(PTR(p, 0x1C0) + 0x14);
        U32(p, 0x3D8) = value;
        U32(p, 0x468) = *(u8 *)(PTR(p, 0x1C0) + 0x14);
        Heap_Free(PTR(p, 0x1C0));
        Heap_Free(PTR(p, 4));
        PTR(p, 4) = NULL;
        ov81_02240CD4(p);
        p[0x13] &= ~0x40;
        U32(p, 0x478) = 0;
        return TRUE;
    }
    return FALSE;
}
