#include "r40_overlay_34_residual_4_private.h"

void ov34_0225DC18(Ov34State *state, int row, void *entry_) {
    int offset;
    u8 *entry = entry_;
    void *window1;
    void *window2;
    void *window3;
    s32 *values;

    offset = row * 0x38;
    values = (s32 *)(state->raw + 0x1F8);
    S32_AT(values, offset) = S32_AT(entry, 0x10);
    CopyToBgTilemapRect(PTR_AT(state, 0x14), 7, 0, (7 * row + 2) & 0xFF, 0x20, 7, (u8 *)PTR_AT(state, 0x24) + 0xC, 0, (S32_AT(values, offset) * 0x18) & 0xFF, 0x20, 0x30);
    window1 = state->raw + 0x1C8;
    FillWindowPixelBuffer((u8 *)window1 + offset, 0);
    window2 = state->raw + 0x1D8;
    FillWindowPixelBuffer((u8 *)window2 + offset, 0);
    window3 = state->raw + 0x1E8;
    FillWindowPixelBuffer((u8 *)window3 + offset, 0);
    AddTextPrinterParameterizedWithColor((u8 *)window1 + offset, 1, PTR_AT(entry, 0), 0, 1, 0xFF, 0x000F0200, NULL);
    AddTextPrinterParameterizedWithColor((u8 *)window2 + offset, 1, PTR_AT(entry, 4), 0, 0, 0xFF, 0x00010200, NULL);
    ScheduleWindowCopyToVram((u8 *)window1 + offset);
    ScheduleWindowCopyToVram((u8 *)window2 + offset);
    if (PTR_AT(entry, 8) != NULL) {
        AddTextPrinterParameterizedWithColor((u8 *)window3 + offset, 1, PTR_AT(entry, 8), 0, 1, 0xFF, 0x000F0200, NULL);
    }
    ScheduleWindowCopyToVram((u8 *)window3 + offset);
}

void ov34_0225DD04(Ov34State *state) {
    int index;
    int count;
    int i;
    void *buffer;

    index = ov34_0225DC0C(S32_AT(PTR_AT(state, 0x270), 0x34C), U16_AT(state, 0x288));
    count = S32_AT(PTR_AT(state, 0x270), 0x348);
    if (count > 3) {
        count = 3;
    }
    if (U16_AT(state, 0x288) != S32_AT(state, 0x28C)) {
        ov34_0225E560(state);
        S32_AT(state, 0x28C) = U16_AT(state, 0x288);
    }
    if (S32_AT(state, 0x294) == 1) {
        for (i = 0; i < count; i++) {
            ov34_0225DC18(state, i, (u8 *)PTR_AT(state, 0x270) + index * 0x1C);
            index = ov34_0225DC00(PTR_AT(state, 0x270), index);
        }
        buffer = GetBgTilemapBuffer(PTR_AT(state, 0x14), 7);
        DC_FlushRange(buffer, 0x600);
        buffer = GetBgTilemapBuffer(PTR_AT(state, 0x14), 7);
        BgCopyOrUncompressTilemapBufferRangeToVram(PTR_AT(state, 0x14), 7, buffer, 0x600, 0);
        S32_AT(state, 0x294) = 0;
    }
}
