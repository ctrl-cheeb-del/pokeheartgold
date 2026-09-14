#include "r47_overlay05_residual6_private.h"

int ov05_0221C908(Overlay05State *state) {
    u32 result;
    if (ov05_0221E9F8(state) == 0) {
        state->stateTimer = 1;
        return 1;
    }
    if (U32_AT(state, 0xBD0) == 0 && PTR_AT(state, 0xBC0) != NULL) {
        return 0;
    }
    if (U32_AT(state, 0xBBC) == 5) {
        return 0;
    }
    if (U32_AT(state, 0xBBC) != 6 && U32_AT(state, 0xBBC) != 5 && U32_AT(state, 0xBBC) != 7 && U32_AT(state, 0xBBC) != 8) {
        U32_AT(state, 0xBBC) = 7;
        state->stateStep = 0xff;
    }
    switch (state->stateStep) {
    case 0:
        ov05_0221E9C4(state);
        ReadMsgDataIntoString(PTR_AT(state, 0xBAC), 8, PTR_AT(state, 0xBB4));
        U32_AT(state, 0xBB8) = AddTextPrinterParameterized((u8 *)state + 0xB88, 1, PTR_AT(state, 0xBB4), 0, 0, 0, NULL);
        ov05_0221EA18(state);
        state->stateStep++;
        break;
    case 1:
        result = sub_0202FE14(PTR_AT(PTR_AT(PTR_AT(state, 0), 0), 0x1C0), *((u8 *)PTR_AT(state, 0) + 0x2C), 0, 0, (u8 *)state + 0xB84, (u8 *)state + 0xB86);
        if (result == 2) {
            ReadMsgDataIntoString(PTR_AT(state, 0xBAC), 6, PTR_AT(state, 0xBB4));
            PlaySE(0x61A);
        } else if (result != 3) {
            break;
        } else {
            ReadMsgDataIntoString(PTR_AT(state, 0xBAC), 7, PTR_AT(state, 0xBB4));
        }
        ov05_0221EA38(state);
        FillWindowPixelRect((u8 *)state + 0xB88, 0xF, 0, 0, 0xD8, 0x20);
        U32_AT(state, 0xBB8) = AddTextPrinterParameterized((u8 *)state + 0xB88, 1, PTR_AT(state, 0xBB4), 0, 0, 0, NULL);
        state->stateTimer = 0;
        state->stateStep++;
        break;
    case 2:
        state->stateTimer++;
        if (state->stateTimer > 30) {
            state->stateTimer = 0;
            state->stateStep++;
        }
        break;
    default:
        ClearFrameAndWindow2((u8 *)state + 0xB88, 0);
        ScheduleBgTilemapBufferTransfer(PTR_AT(state, 0xC), 0);
        state->stateStep = 0;
        state->stateTimer = 0x15;
        return 1;
    }
    ScheduleBgTilemapBufferTransfer(PTR_AT(state, 0xC), 0);
    return 0;
}

int ov05_0221CAB8(Overlay05State *state) {
    switch (state->stateStep) {
    case 0:
        if (ov05_0221E9F8(state) == 0) {
            GfGfx_EngineATogglePlanes(1, 0);
        }
        ov05_0221E9C4(state);
        ReadMsgDataIntoString(PTR_AT(state, 0xBAC), 9, PTR_AT(state, 0xBB4));
        U32_AT(state, 0xBB8) = AddTextPrinterParameterized((u8 *)state + 0xB88, 1, PTR_AT(state, 0xBB4), 0, 0, 0, NULL);
        sub_02037AC0(0x3E);
        if (PTR_AT(state, 0xBC8) == NULL && ov05_0221E9F8(state) == 1) {
            GfGfx_EngineATogglePlanes(1, 1);
        }
        state->stateStep++;
        break;
    case 1:
        if (sub_02037B38(0x3E)) {
            state->stateStep = 0;
            return 1;
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    ScheduleBgTilemapBufferTransfer(PTR_AT(state, 0xC), 0);
    return 0;
}

int ov05_0221CB70(Overlay05State *state) {
    if (ov05_0221CCF4(state) == 1) {
        if (U8_AT(PTR_AT(state, 0), 0x2A) == 1) {
            PaletteData_CopyPalette(PTR_AT(state, 8), 0, 0x40, 0, 0x30, 0x20);
        } else {
            PaletteData_CopyPalette(PTR_AT(state, 8), 0, 0x40, 0, 0, 0x20);
        }
    } else {
        if (U8_AT(PTR_AT(state, 0), 0x2A) == 1) {
            PaletteData_CopyPalette(PTR_AT(state, 8), 0, 0x40, 0, 0, 0x20);
        } else {
            PaletteData_CopyPalette(PTR_AT(state, 8), 0, 0x40, 0, 0x30, 0x20);
        }
    }
    PaletteData_SetSelectedBufferAll(PTR_AT(state, 8), 1);
    PlaySE(0x71B);
    state->stateTimer = 0x40;
    return 1;
}

int ov05_0221CC04(Overlay05State *state) {
    if (state->stateStep == 0) {
        PlaySE(0x719);
    }
    if (state->stateStep == 16) {
        state->stateStep = 0;
        state->stateTimer = 0x40;
        return 1;
    }
    state->stateStep++;
    ov05_0221E564(state, (s16)(16 - state->stateStep));
    ov05_0221DE6C(state, state->stateStep);
    return 0;
}
