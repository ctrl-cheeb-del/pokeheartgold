#include "to47_overlay87_private.h"

int ScratchOffCards_Exit(void *m) {
    State *p = OverlayManager_GetData(m);
    sub_02021238();
    **(u16 **)((u8 *)p + 0x374) = *((u8 *)p + 0xc);
    GF_DestroyVramTransferManager();
    ov87_021E6780(p);
    OverlayManager_FreeData(m);
    Main_SetVBlankIntrCB(0, 0);
    Heap_Destroy(0x7a);
    return 1;
}
int ov87_021E5AFC(u8 *p) {
    switch (p[8]) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 3, 0x7a);
        p[8]++;
        break;
    case 1:
        if (IsPaletteFadeFinished() == 1) {
            p[14] = 0;
            return 1;
        }
        break;
    }
    return 0;
}
