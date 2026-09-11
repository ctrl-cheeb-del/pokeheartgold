#include "unk_0208C3E4_internal.h"

void sub_0208C3E4(SummaryState *state) {
    u16 i;
    for (i = 0; i < 34; i++) {
        AddWindow(state->bgConfig, &state->windows[i], &_02104D94[i]);
        FillWindowPixelBuffer(&state->windows[i], 0);
    }
    sub_0208C9A4(state);
    sub_0208C57C(state);
    sub_0208C614(state);
    sub_0208C6B4(state);
}

void sub_0208C42C(SummaryState *state) {
    const WindowTemplate *templates;
    u32 i;

    switch (S8(state, 0x7bc)) {
    case 0:
        templates = _02104CC4;
        U32(state, 0x228) = 8;
        break;
    case 1:
        templates = _02104D04;
        U32(state, 0x228) = 18;
        break;
    case 2:
        templates = _02104C84;
        U32(state, 0x228) = 8;
        break;
    case 3:
        if (U8((SummaryState *)PTR(state, 0x22c, void), 0x12) != 3 && U8((SummaryState *)PTR(state, 0x22c, void), 0x12) != 4) {
            return;
        }
        U32(state, 0x228) = 3;
        break;
    default:
        return;
    }

    PTR(state, 0x224, Window) = AllocWindows(0x13, U32(state, 0x228));
    for (i = 0; i < U32(state, 0x228); i++) {
        AddWindow(PTR(state, 0, void), &PTR(state, 0x224, Window)[i], &templates[i]);
    }
}
