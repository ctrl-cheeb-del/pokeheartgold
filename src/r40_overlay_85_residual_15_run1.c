#include "r40_overlay_85_residual_15_private.h"

void ov85_021E6E14(u8 *ctx) {
    void *p = PaletteData_Init(0x66);
    *(void **)(ctx + 0xd9c) = p;
    PaletteData_SetAutoTransparent(*(void **)(ctx + 0xd9c), 1);
    PaletteData_AllocBuffers(*(void **)(ctx + 0xd9c), 0, 0x200, 0x66);
    PaletteData_AllocBuffers(*(void **)(ctx + 0xd9c), 2, 0x200, 0x66);
    PaletteData_AllocBuffers(*(void **)(ctx + 0xd9c), 1, 0x200, 0x66);
    PaletteData_AllocBuffers(*(void **)(ctx + 0xd9c), 3, 0x200, 0x66);
}

void ov85_021E6E6C(u8 *ctx) {
    PaletteData_FreeBuffers(*(void **)(ctx + 0xd9c), 0);
    PaletteData_FreeBuffers(*(void **)(ctx + 0xd9c), 2);
    PaletteData_FreeBuffers(*(void **)(ctx + 0xd9c), 1);
    PaletteData_FreeBuffers(*(void **)(ctx + 0xd9c), 3);
    PaletteData_Free(*(void **)(ctx + 0xd9c));
}
