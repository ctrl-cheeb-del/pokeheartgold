#include "overlay81_results_screen_r4_private.h"

void ov81_022403C0(void *work) {
    ov81_02240210();
    ov81_02240230(OV81_R4_PTR(work, 0x4C));
    OV81_R4_PTR(work, 0x1A0) = PaletteData_Init(100);
    PaletteData_AllocBuffers(OV81_R4_PTR(work, 0x1A0), 2, 0x200, 100);
    PaletteData_AllocBuffers(OV81_R4_PTR(work, 0x1A0), 0, 0x200, 100);
    ov81_02240770();
    ov81_02240728(work, 6);
    ov81_02240698(work, 3);
    ov81_022406E0(work, 2);
    if (((u32)OV81_R4_U8(work, 0x13) << 27) >> 31) {
        BgSetPosTextAndCommit(OV81_R4_PTR(work, 0x4C), 6, 0, *(s32 *)((u8 *)work + 0xC));
    }
    GfGfx_EngineATogglePlanes(2, 1);
    GfGfx_EngineATogglePlanes(4, 0);
    GfGfx_EngineATogglePlanes(8, 1);
    ov81_022407A8(work, 7);
}
