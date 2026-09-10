#include "field_object_attachment_internal.h"

void *ov01_021F467C(void *arg0, void *arg1) {
    u32 *handle;
    Ov01BgConfig config;

    GfGfx_EngineATogglePlanes(2, FALSE);
    GfGfx_EngineATogglePlanes(4, FALSE);
    GfGfx_EngineATogglePlanes(8, FALSE);
    GX_ResetBankForBG();
    handle = Heap_Alloc(4, 4);
    MIi_CpuClear32(0, handle, 4);
    config = ov01_02206B94;
    config.words[8] = (u32)arg0;
    config.words[9] = (u32)arg1;
    *handle = (u32)ov01_021F4464(&config);
    return handle;
}

void ov01_021F46DC(void *v) {
    void **handle = v;

    ov01_021F44B4(*handle, 1, 0, 1);
    GX_SetBankForBG(GX_VRAM_BG_128_C);
    GfGfx_EngineATogglePlanes(0xE, TRUE);
    Heap_FreeExplicit(4, *handle);
}
