#include "overlay83_setup_r46_27_private.h"

void ov83_02244394(void *p) {
    PaletteData *pal;
    u16 v = *(vu16 *)0x04000304;
    u32 mask = 0xffff7fff;
    *(vu16 *)0x04000304 = v & mask;
    ov83_022444C0();
    ov83_022444E0(PTR(p, 0x4c));
    pal = PaletteData_Init(HEAP_ID_107);
    PTR(p, 0x2b0) = pal;
    PaletteData_AllocBuffers(PTR(p, 0x2b0), PLTTBUF_MAIN_OBJ, 0x200, HEAP_ID_107);
    PaletteData_AllocBuffers(PTR(p, 0x2b0), PLTTBUF_MAIN_BG, 0x200, HEAP_ID_107);
    ov83_0224465C(p, 3);
    ov83_022446D0();
    ov83_02244704(p, 2);
    ov83_0224474C();
    GfGfx_EngineATogglePlanes(4, 0);
    ov83_02244780(p, 4);
}
