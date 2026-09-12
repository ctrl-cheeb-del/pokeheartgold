#include "overlay81_screen_setup_r6_private.h"

void ov81_02240CD4(void *work) {
    ov81_02240D2C();
    PTR(work, 0x1a4) = GF_3DVramMan_Create(0x64, 0, 2, 0, 2, ov81_02242BC8);
    PTR(work, 0x4c) = BgConfig_Alloc(0x64);
    ov81_02240D64(work);
    ov81_02242FDC(PTR(work, 0x4c), (u8 *)work + 0x50);
    if (U32(work, 0x47c) == 2) {
        ov81_022430E8((u8 *)work + 0x70);
    }
}

void ov81_02240D2C(void) {
    volatile u32 *regMain = (u32 *)0x04000000;
    volatile u32 *regSub = (u32 *)0x04001000;
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *regMain &= 0xffffe0ff;
    *regSub &= 0xffffe0ff;
}
