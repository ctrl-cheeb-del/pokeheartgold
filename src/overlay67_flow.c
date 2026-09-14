#include "overlay67_flow_internal.h"

#define U16_AT(p, offset) (*(u16 *)((u8 *)(p) + (offset)))
#define U32_AT(p, offset) (*(u32 *)((u8 *)(p) + (offset)))

BOOL ov67_021E5984(OverlayManager *manager, int *step) {
    Ov67State *state = OverlayManager_GetData(manager);

    switch (*step) {
    case 0:
        if (ov67_021E5A6C(state)) {
            *step = 1;
        }
        break;
    case 1:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, U32_AT(state, 0));
        *step = 2;
        break;
    case 2:
        if (IsPaletteFadeFinished()) {
            if (U16_AT(state, 8) == 0) {
                *step = 3;
            } else {
                *step = 4;
            }
        }
        break;
    case 3:
        *step = ov67_021E5C04(state);
        break;
    case 4:
        *step = ov67_021E5C44(state);
        break;
    case 5:
        if (!ov67_021E6A40(state)) {
            *step = U32_AT(state, 0x49C);
        }
        break;
    case 6:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, U32_AT(state, 0));
        *step = 7;
        break;
    case 7:
        if (IsPaletteFadeFinished()) {
            *step = 8;
        }
        break;
    case 8:
        if (ov67_021E5B44(state)) {
            return TRUE;
        }
        break;
    }

    if (*step >= 1 && *step <= 7) {
        ov67_021E69D8(state);
    }
    return FALSE;
}

BOOL ov67_021E5A6C(Ov67State *state) {
    switch (U32_AT(state, 4)) {
    case 0:
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
        *(volatile u32 *)0x04001000 = 0xFFFFE0FF & *(volatile u32 *)0x04001000;
        *(volatile u16 *)0x04000304 = 0xFFFF7FFF & *(volatile u16 *)0x04000304;
        ov67_021E5BC0();
        ResetVisibleHardwareWindows(0);
        ResetVisibleHardwareWindows(1);
        ov67_021E5DA0(state);
        break;
    case 1:
        ov67_021E5EB0(state);
        ov67_021E60B4(state);
        break;
    case 2:
        ov67_021E6820(state);
        break;
    case 3:
        ov67_021E6008(state);
        if (U16_AT(state, 8) == 0) {
            ov67_021E6220(state);
        } else {
            ov67_021E63E8(state);
            ov67_021E65C0(state);
            ov67_021E681C(state);
            ov67_021E6BC4(state);
        }
        break;
    case 4:
        Main_SetVBlankIntrCB(ov67_021E5BE0, state);
        U32_AT(state, 4) = 0;
        return TRUE;
    }
    U32_AT(state, 4)
    ++;
    return FALSE;
}

BOOL ov67_021E5B44(Ov67State *state) {
    switch (U32_AT(state, 4)) {
    case 0:
        if (U16_AT(state, 8) != 0) {
            ov67_021E6C04(state);
            ov67_021E6474(state);
        }
        ov67_021E6990(state);
        ov67_021E6080(state);
        ov67_021E60F4(state);
        ov67_021E5E84(state);
        break;
    case 1:
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
        *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
        U32_AT(state, 4) = 0;
        return TRUE;
    }
    U32_AT(state, 4)
    ++;
    return FALSE;
}
