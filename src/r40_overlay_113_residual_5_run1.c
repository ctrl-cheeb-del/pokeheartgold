#include "r40_overlay_113_residual_5_private.h"

u8 ov113_021E5D80(State *state) {
    u8 value = U8(state, 0x3C);
    int i;
    for (i = 0; i < 6; i++) {
        if ((s32)(((u32)ov113_021E6BD0[i][0] << 16) >> 24) > (s32)value) {
            break;
        }
    }
    return i;
}

void ov113_021E5DA4(State *state) {
    FillWindowPixelBuffer(state->raw + 0x78, 0);
    FillWindowPixelBuffer(state->raw + 0x88, 0);
    FillWindowPixelBuffer(state->raw + 0x98, 0);
    if (U8(state, 0x1A) == 0) {
        ov113_021E5FC0(state);
    } else if (U8(state, 0x1A) - 1 < U8(state, 0x1C)) {
        ov113_021E6084(state, U8(state, 0x1A) - 1);
    } else {
        ov113_021E613C(state, U8(state, 0x1A) - (U8(state, 0x1C) + 1));
    }
    BufferIntegerAsString(PTR(state, 0x48), 0, U8(state, 0x1A) + 1, 1, 0, 1);
    BufferIntegerAsString(PTR(state, 0x48), 1, U8(state, 0x1B), 1, 0, 1);
    StringExpandPlaceholders(PTR(state, 0x48), PTR(state, 0x50), PTR(state, 0x58));
    AddTextPrinterParameterizedWithColor(state->raw + 0x98, 0, PTR(state, 0x50), 0, 0, 0xFF, 0x000F0200, NULL);
    ScheduleWindowCopyToVram(state->raw + 0x78);
    ScheduleWindowCopyToVram(state->raw + 0x88);
    ScheduleWindowCopyToVram(state->raw + 0x98);
    ov113_021E6B1C(state);
}

void ov113_021E5E64(State *state, int seq) {
    u32 x;
    u32 width;
    Sprite_SetAnimCtrlSeq(PTR(state, 0xB8), seq);
    Sprite_ResetAnimCtrlState(PTR(state, 0xB8));
    FillWindowPixelBuffer(state->raw + 0x68, 0);
    width = FontID_String_GetWidth(4, PTR(state, 0x54), 0);
    x = (0x30 - width) / 2;
    AddTextPrinterParameterizedWithColor(state->raw + 0x68, 4, PTR(state, 0x54), x, 0, 0xFF, 0x00070F00, NULL);
    ScheduleWindowCopyToVram(state->raw + 0x68);
}
