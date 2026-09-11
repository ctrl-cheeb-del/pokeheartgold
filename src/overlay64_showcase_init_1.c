#include "filesystem.h"
#include "gf_gfx_planes.h"
#include "hall_of_fame.h"
#include "heap.h"
#include "overlay64_showcase_init_internal.h"
#include "overlay_64.h"
#include "overlay_manager.h"
#include "system.h"

BOOL HallOfFameShowcase_Init(OverlayManager *man, int *state) {
    Overlay64Work *work;

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_EngineASetPlanes(0);
    GfGfx_EngineBSetPlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    sub_020210BC();
    sub_02021148(4);
    *(volatile u16 *)0x04000304 &= 0xFFFF7FFF;
    Heap_Create(HEAP_ID_3, HEAP_ID_59, 0x40000);
    work = OverlayManager_CreateAndGetData(man, sizeof(Overlay64Work), HEAP_ID_59);
    MI_CpuFill8(work, 0, sizeof(Overlay64Work));
    work->args = OverlayManager_GetArgs(man);
    work->numRecords = Save_HOF_GetNumRecords(work->args);
    work->narc = NARC_New(NARC_a_1_8_0, HEAP_ID_59);
    ov64_021E5B00();
    ov64_021E5B10(work);
    ov64_021E5CD0(work);
    ov64_021E607C(work);
    ov64_021E6170(work);
    ov64_021E622C(work);
    ov64_021E652C(work, 0);
    Main_SetVBlankIntrCB((GFIntrCB)ov64_021E5A88, work);
    return TRUE;
}
