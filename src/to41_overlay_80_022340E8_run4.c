#include "to41_overlay_80_022340E8_private.h"

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

void ov80_02234968(void *ctx, void *data) {
    u8 *p = ctx;
    if (p[0x13] != 0x20) {
        void *unpacked;
        void *narc = NARC_New(0xB7, 0x65);
        void *palette;
        GfGfxLoader_LoadCharDataFromOpenNarc(narc,
            *(const u16 *)((const u8 *)ov80_0223BF5A + p[0x13] * 6),
            *(void **)data,
            2,
            0,
            0,
            1,
            0x65);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc,
            *(const u16 *)((const u8 *)ov80_0223BF5C + p[0x13] * 6),
            *(void **)data,
            2,
            0,
            0,
            1,
            0x65);
        palette = GfGfxLoader_GetPlttDataFromOpenNarc(narc,
            *(const u16 *)((const u8 *)ov80_0223BF5E + p[0x13] * 6),
            &unpacked,
            0x65);
        DC_FlushRange(*(void **)((u8 *)unpacked + 0xC), *(u32 *)((u8 *)unpacked + 8));
        GX_BeginLoadBGExtPltt();
        GX_LoadBGExtPltt(*(void **)((u8 *)unpacked + 0xC), 0x4000, 0x2000);
        GX_EndLoadBGExtPltt();
        Heap_Free(palette);
        GfGfx_EngineATogglePlanes(4, TRUE);
        ScheduleBgTilemapBufferTransfer(*(void **)data, 2);
        NARC_Delete(narc);
    } else {
        GfGfx_EngineATogglePlanes(4, FALSE);
    }
}

void ov80_02234A38(void *unused, void *data) {
    void *narc = NARC_New(0xB7, 0x65);
    void *bgConfig = *(void **)data;
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x39, bgConfig, 3, 0, 0, 1, 0x65);
    ScheduleBgTilemapBufferTransfer(*(void **)data, 3);
    NARC_Delete(narc);
}
