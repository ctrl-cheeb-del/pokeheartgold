#include "ov83_wave42_private.h"

void ov83_0223F7E4(void);

void ov83_0223F690(void *p) {
    void *pal;
    u16 v = *(vu16 *)0x04000304;
    u32 mask = 0xffff7fff;
    *(vu16 *)0x04000304 = v & mask;
    ov83_0223F7E4();
    ov83_0223F804(PTR(p, 0x4c));
    pal = PaletteData_Init(0x6b);
    PTR(p, 0x500) = pal;
    PaletteData_AllocBuffers(PTR(p, 0x500), 2, 0x200, 0x6b);
    PaletteData_AllocBuffers(PTR(p, 0x500), 0, 0x200, 0x6b);
    ov83_0223FA00(p, 3);
    ov83_0223FA74();
    ov83_0223FAA8(p, 2);
    ov83_0223FAF0();
    ov83_022477EC(2, 0, (u8 *)p + 0x868);
    ov83_0223FBEC(p, 4);
}

void ov83_0223F70C(void *p) {
    int n = ov80_02237D8C(U8(p, 9));
    ov83_02246E08((u8 *)p + 0x518, PTR(p, 0x7a4), n);
}

void ov83_0223F734(void *p) {
    GfGfx_EngineATogglePlanes(0x1f, 0);
    GfGfx_EngineBTogglePlanes(0x1f, 0);
    FreeBgTilemapBuffer(p, 3);
    FreeBgTilemapBuffer(p, 2);
    FreeBgTilemapBuffer(p, 0);
    FreeBgTilemapBuffer(p, 1);
    FreeBgTilemapBuffer(p, 4);
    FreeBgTilemapBuffer(p, 5);
    FreeBgTilemapBuffer(p, 6);
    FreeBgTilemapBuffer(p, 7);
    Heap_Free(p);
    *(vu16 *)0x04000304 |= 0x8000;
}

void ov83_0223F7A0(void *p) {
    vu32 *base = (vu32 *)0x027e0000;
    if (PTR(p, 0x500)) {
        PaletteData_PushTransparentBuffers(PTR(p, 0x500));
    }
    DoScheduledBgGpuUpdates(PTR(p, 0x4c));
    ov83_0224780C((u8 *)p + 0x868);
    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    base[0x3ff8 / 4] |= 1;
}

void ov83_0223F7E4(void) {
    SolBanks b = ov83_02247E88;
    GfGfx_SetBanks(&b);
}
