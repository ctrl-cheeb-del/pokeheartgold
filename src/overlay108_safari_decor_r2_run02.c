#include "overlay108_safari_decor_r2_private.h"

void ov108_021E8A88(void *p) {
    Heap_Free(PTR(p, 0x334));
    SafariZone_SetAreaSet(PTR(p, 0x20), 0, (u8 *)p + 0x24);
    if (U8(p, 0x431) >= 6) {
        U8(p, 0x431) = 5;
    }
    U8(PTR(PTR(p, 0x1c), 0x20), 0) = U8(p, 0x431) + 6 * U8(p, 0x430);
    MenuInputStateMgr_SetState(PTR(PTR(p, 0x1c), 4), U32(p, 0x10));
}

void ov108_021E8AD4(void) {
    Main_SetVBlankIntrCB(0, 0);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    sub_0200FBF4(0, 0);
    sub_0200FBF4(1, 0);
    ResetVisibleHardwareWindows(0);
    ResetVisibleHardwareWindows(1);
}

int ov108_021E8B24(void *p) {
    switch (U32(p, 4)) {
    case 0:
        U32(p, 4) = ov108_021E9388(p);
        break;
    case 1:
        U32(p, 4) = 0;
        return 2;
    case 2:
        U32(p, 4) = ov108_021E93A8(p);
        break;
    case 3:
        U32(p, 4) = 0;
        return U32(p, 0xc);
    }
    return 1;
}

int ov108_021E8B68(void *p) {
    switch (U32(p, 4)) {
    case 0:
        ov108_021E940C(p, 1);
        ov108_021E9488(p);
        U32(p, 4)
        ++;
        break;
    case 1: {
        int r = ov108_021E94E8(p);
        if (r < 0) {
            break;
        }
        if (r == 1) {
            ov108_021E8C64(p);
            U32(p, 4) = 0;
            return 3;
        }
        U32(p, 4)
        ++;
        break;
    }
    default:
        ov108_021E940C(p, 0);
        U32(p, 4) = 0;
        return 1;
    }
    return 2;
}

int ov108_021E8BC0(void *p) {
    switch (U32(p, 4)) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, U32(p, 0));
        GfGfx_EngineATogglePlanes(0x10, 1);
        GfGfx_EngineBTogglePlanes(0x10, 1);
        U32(p, 4)
        ++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            U32(p, 4) = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int ov108_021E8C18(void *p) {
    switch (U32(p, 4)) {
    case 0:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, U32(p, 0));
        U32(p, 4)
        ++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            U32(p, 4) = 0;
            return 4;
        }
        break;
    }
    return 3;
}

void ov108_021E8C64(void *p) {
    u8 object[4];
    SafariDecorRecord *entry;
    MI_CpuFill8(object, 0, sizeof(object));
    entry = (SafariDecorRecord *)PTR(p, 0x334) + U8(p, 0x432);
    object[0] = entry->id;
    object[1] = ((SafariArgsLayout *)PTR(p, 0x1c))->areas[entry->area].value1 % 32;
    object[3] = ((SafariArgsLayout *)PTR(p, 0x1c))->areas[entry->area].value3 % 32;
    object[2] = ((SafariArgsLayout *)PTR(p, 0x1c))->type;
    SafariZone_AddObjectToArea((u8 *)p + 0x24, ((SafariArgsLayout *)PTR(p, 0x1c))->area, object);
    ((SafariArgsLayout *)PTR(p, 0x1c))->lastObject = object[0];
}
