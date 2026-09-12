#include "overlay102_graphics_r14_private.h"

#define PTR(base, off) (*(void **)((u8 *)(base) + (off)))
#define U32(base, off) (*(u32 *)((u8 *)(base) + (off)))

void ov102_021E94A4(void *state) {
    u8 *p = state;
    SysTask_Destroy(PTR(PTR(p, 0), U32(p, 0x10) * 4 + 8));
    PTR(PTR(p, 0), U32(p, 0x10) * 4 + 8) = NULL;
    Heap_Free(p);
}

void ov102_021E94CC(void *task, void *state) {
#pragma unused(task)
    u8 *p = state;
    void *narc;
    volatile u32 *regA = (volatile u32 *)0x04000000;
    volatile u32 *regB = (volatile u32 *)0x04001000;

    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *regA &= 0xFFFFE0FF;
    *regB &= 0xFFFFE0FF;
    *regA = (*regA & 0xFFCFFFEF) | 0x00100010;
    *regB = (*regB & 0xFFCFFFEF) | 0x10;
    narc = NARC_New(0x4C, 0x23);
    ov102_021E978C(p);
    ov102_021E95E0(p, narc);
    ov102_021E91C4(PTR(p, 0));
    PTR(PTR(p, 0), 0x1E0) = ov102_021EA314(PTR(p, 0), PTR(p, 4), PTR(p, 8));
    ov102_021EA41C(PTR(PTR(p, 0), 0x1E0), narc);
    PTR(PTR(p, 0), 0x1E4) = ov102_021EB1A4(PTR(p, 0), PTR(p, 4), PTR(p, 8));
    ov102_021EB1F8(PTR(PTR(p, 0), 0x1E4), narc);
    PTR(PTR(p, 0), 0x1E8) = ov102_021EB694(PTR(p, 0), PTR(p, 4), PTR(p, 8));
    ov102_021EB6E0(PTR(PTR(p, 0), 0x1E8), narc);
    PTR(PTR(p, 0), 0x1EC) = ov102_021EBC34(PTR(p, 0), PTR(p, 4), PTR(p, 8));
    ov102_021EBD00(PTR(PTR(p, 0), 0x1EC));
    PTR(PTR(p, 0), 0x1F0) = ov102_021EC20C(PTR(p, 0), PTR(p, 4), PTR(p, 8));
    ov102_021EC248(PTR(PTR(p, 0), 0x1F0), narc);
    GfGfx_EngineATogglePlanes(0x10, TRUE);
    GfGfx_EngineBTogglePlanes(0x10, TRUE);
    GX_DispOn();
    NARC_Delete(narc);
    ov102_021E94A4(p);
}
