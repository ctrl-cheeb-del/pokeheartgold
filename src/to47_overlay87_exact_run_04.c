#include "to47_overlay87_private.h"

void ov87_021E68A4(void) {
    volatile u32 *a = (volatile u32 *)0x04000000;
    volatile u32 *b = (volatile u32 *)0x04001000;
    Main_SetVBlankIntrCB(0, 0);
    Main_SetHBlankIntrCB(0, 0);
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *a &= 0xffffe0ff;
    *b &= 0xffffe0ff;
}
